/**************************************************************************
** CanvasEngine is a C11 cross platform multimedia library.              **
** Copyright (C) 2025 Jacob Isonell (isonelljacob@gmail.com)             **
**                                                                       **
** This program is free software: you can redistribute it and/or modify  **
** it under the terms of the GNU General Public License as published by  **
** the Free Software Foundation, either version 3 of the License, or     **
** (at your option) any later version.                                   **
**                                                                       **
** This program is distributed in the hope that it will be useful,       **
** but WITHOUT ANY WARRANTY; without even the implied warranty of        **
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          **
** GNU General Public License for more details.                          **
**                                                                       **
** You should have received a copy of the GNU General Public License     **
** along with this program. If not, see <https://www.gnu.org/licenses/>. **
**************************************************************************/

#include "idx12_protos.h"

#define IFX_GPU_ADAPTER_TYPE ice_gpu_adapter_dx12
#define IFX_GPU_ADAPTER_VAR dx12
#include "ifx_get_adapters.inl"

static ce_err s_load(
  CE_INOUT idx12_protos* prot
);

static void irelease_driver(
  CE_INOUT ce_render_driver* self
);
  
static ce_err ifetch_gpu_adapters(
  CE_INOUT ce_render_driver*   self,
           ce_gpu_adapter_pref order_pref
);

static ce_err s_grow_adapters_arr(
  CE_INOUT ce_arr(ice_gpu_adapter_dx12)* arr
);

static DXGI_GPU_PREFERENCE s_to_dxgi_gpu_pref(
  ce_gpu_adapter_pref in
);

#define IDX_ENUMFUNC_NAME s_enum_fact6
#define IDX_ENUMFACT IDXGIFactory6
#define IDX_ENUMFUNC(fact, index, order, uuid, ptr) fact->lpVtbl->EnumAdapterByGpuPreference(fact, index, order, uuid, ptr)
#include "idx_enum_adapters.inl"

#undef IDX_ENUMFUNC_NAME
#undef IDX_ENUMFACT
#undef IDX_ENUMFUNC

#define IDX_ENUMFUNC_NAME s_enum_fact
#define IDX_ENUMFACT IDXGIFactory2
#define IDX_ENUMFUNC(fact, index, order, uuid, ptr) fact->lpVtbl->EnumAdapters(fact, index, (IDXGIAdapter**)ptr)
#include "idx_enum_adapters.inl"

#undef IDX_ENUMFUNC_NAME
#undef IDX_ENUMFACT
#undef IDX_ENUMFUNC

static const ce_render_driver_vfp s_vfp = {
  .release = &irelease_driver,
  .fetch_gpu_adapters = &ifetch_gpu_adapters,
  .get_gpu_adapters = &iget_gpu_adapters,
};

static void s_enable_debinfo(const idx12_protos* prot) {
  ID3D12Debug* d3d12debug = NULL;
  ID3D12Tools* d3d12tools = NULL;
  HRESULT errcode;
  
  errcode = prot->D3D12GetInterface(&CLSID_D3D12Debug, IDX_UUIDOF(d3d12debug), (void**)&d3d12debug);
  if (d3d12debug) {
    d3d12debug->lpVtbl->EnableDebugLayer(d3d12debug);
    d3d12debug->lpVtbl->Release(d3d12debug);
  } else {
  #ifdef CANVAS_DEBUG
    char msgbuff[256];
    ice_win32err_s(msgbuff, CE_ARRLEN(msgbuff), (DWORD)errcode, ICE_DEFLANG);
    IDEBWARN("D3D12GetInterface (ID3D12Debug) failed! \"%s\"\n", msgbuff);
  #else
    (void)errcode;
  #endif
  }
  
  errcode = prot->D3D12GetInterface(&CLSID_D3D12Tools, IDX_UUIDOF(d3d12tools), (void**)&d3d12tools);
  if (d3d12tools) {
    d3d12tools->lpVtbl->EnableShaderInstrumentation(d3d12tools, TRUE);
    d3d12tools->lpVtbl->Release(d3d12tools);
  } else {
  #ifdef CANVAS_DEBUG
    char msgbuff[256];
    ice_win32err_s(msgbuff, CE_ARRLEN(msgbuff), (DWORD)errcode, ICE_DEFLANG);
    IDEBWARN("D3D12GetInterface (ID3D12Tools) failed! \"%s\"\n", msgbuff);
  #else
    (void)errcode;
  #endif
  }
}

CE_API ce_err ce_directx12_driver(
  CE_OUT ce_render_driver* driver,
  CE_IN  const ce_directx12_driver_create_info* info
) {
  if (driver == NULL || info == NULL) {
    return CE_EINVAL;
  }
  
  const UINT dxgifact_flags = info->enable_debug
    ? DXGI_CREATE_FACTORY_DEBUG
    : 0;
  
  ice_directx12_driver_data* dxp = NULL;
  IERRBEGIN {
    driver->vfp = &s_vfp;
    
    dxp = IERRALLOC_TYPE(ice_directx12_driver_data);
    driver->data.dx12 = dxp;
    *dxp = (ice_directx12_driver_data) {0};
    
    idx12_protos* const pfn = &dxp->pfn;
    IERRDO(ce_lib_open(&pfn->libd3d12, "d3d12.dll", CE_LIB_FLAG_NONE));
    IERRDO(ce_lib_open(&pfn->libdxgi, "dxgi.dll", CE_LIB_FLAG_NONE));
    IERRDO(s_load(pfn));
    
    IERRDO(ifrom_hres(pfn->CreateDXGIFactory2(dxgifact_flags, IDX_UUIDOF(dxp->fact), (void**)&dxp->fact)));
    
    if (info->enable_debug) {
      s_enable_debinfo(pfn);
    }
    
  } IERREND {
    if (dxp != NULL) {
      ce_lib_close(dxp->pfn.libdxgi);
      ce_lib_close(dxp->pfn.libd3d12);
      if (dxp->fact != NULL) {
        dxp->fact->lpVtbl->Release(dxp->fact);
      }
    }
    ifree(dxp, sizeof(*dxp));
    *driver = (ce_render_driver) {0};
  }
  
  return IERRVAL;
}

static void irelease_driver(
  CE_INOUT ce_render_driver* self
) {
  ice_directx12_driver_data* const data = self->data.dx12;
  idx12_protos* const p = &(data->pfn);
  
  IDXGIFactory2* const fact = data->fact;
  fact->lpVtbl->Release(fact);
  
  ce_arr_free(data->gpu_adapters);
  ce_lib_close(p->libd3d12);
  ce_lib_close(p->libdxgi);
  ifree(data, sizeof(*(data)));
  
  *self = (ce_render_driver) {0};
}

static ce_err ifetch_gpu_adapters(
  CE_INOUT ce_render_driver*   self,
           ce_gpu_adapter_pref order_pref
) {
  ice_directx12_driver_data* const dxp = self->data.dx12;
  ce_arr(ice_gpu_adapter_dx12)* adapters = &dxp->gpu_adapters;
  IDXGIFactory2* const fact = dxp->fact;
  
  const DXGI_GPU_PREFERENCE gpu_pref = s_to_dxgi_gpu_pref(order_pref);
  
  IDXGIFactory6* fact6 = NULL;
  IDXGIFactory4* fact4 = NULL;
  HRESULT hcode;
  
  IERRBEGIN {
    
    /* Clear old adapters */
    IERRDO(ce_arr_resize(adapters, 0, sizeof(**adapters)));
    
    /* Query adapters. */
    hcode = fact->lpVtbl->QueryInterface(fact, IDX_UUIDOF(fact6), (void**)fact6);
    if (SUCCEEDED(hcode)) {
      IERRDO(s_enum_fact6(adapters, fact6, gpu_pref));
    } else {
      IERRDO(s_enum_fact(adapters, fact, gpu_pref));
    }
    
    /* Try to get the Warp adapter. */
    hcode = fact->lpVtbl->QueryInterface(fact, IDX_UUIDOF(fact4), (void**)fact4);
    if (SUCCEEDED(hcode)) {
      const size_t len = ce_arr_size(*adapters) + 1;
      IERRDO(ce_arr_resize(adapters, len, sizeof(**adapters)));
      ice_gpu_adapter_dx12* const out = (*adapters) + len;
      out->is_warp = cetrue;
      
      hcode = fact4->lpVtbl->EnumWarpAdapter(fact4, IDX_UUIDOF(out->adap), (void**)&out->adap);
      if (FAILED(hcode)) {
        ce_arr_resize(adapters, len - 1, sizeof(**adapters));
        IERRDO(ifrom_hres(hcode));
      }
    }
    
  #ifdef CANVAS_DEBUG
    
    /* TEMPORARY */
    const size_t len = ce_arr_size(*adapters);
    for (size_t i = 0; i < len; ++i) {
      ice_gpu_adapter_dx12* const it = (*adapters) + i;
      printf(IASCII_CYAN " -- Adapter #%zu (%p)%s\n" IASCII_RESET, i + 1, it->adap, (it->is_warp ? " (Warp Adapter)" : ""));
    }
    
  #endif /* !CANVAS_DEBUG */
    
  } IERREND { }
  
  if (fact6 != NULL) {
    fact6->lpVtbl->Release(fact6);
  }
  
  if (fact4 != NULL) {
    fact4->lpVtbl->Release(fact4);
  }
  
  return IERRVAL;
}

static ce_err s_grow_adapters_arr(
  CE_INOUT ce_arr(ice_gpu_adapter_dx12)* arr
) {
  const size_t len = ce_arr_size(*arr);
  const size_t cap = ce_arr_cap(*arr);
  
  if (len < cap) {
    return CE_EOK;
  }
  
  return ce_arr_reserve(arr, cap + cap / 2, sizeof(**arr));
}

static DXGI_GPU_PREFERENCE s_to_dxgi_gpu_pref(
  ce_gpu_adapter_pref in
) {
  switch (in) {
  default: return DXGI_GPU_PREFERENCE_UNSPECIFIED;
  case CE_GPU_ADAPTER_PREF_PERFORMANCE: return DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE;
  case CE_GPU_ADAPTER_PREF_MINPOWER: return DXGI_GPU_PREFERENCE_MINIMUM_POWER;
  }
}

static ce_err s_load(
  CE_INOUT idx12_protos* prot
) {
#define LOAD_D3D12(name) IERRDO(ce_lib_load(prot->libd3d12, #name, (void*)&prot->name))
#define LOAD_DXGI(name) IERRDO(ce_lib_load(prot->libdxgi, #name, (void*)&prot->name))
  
  IERRBEGIN {
    LOAD_D3D12(D3D12CreateDevice);
    LOAD_D3D12(D3D12CreateRootSignatureDeserializer);
    LOAD_D3D12(D3D12CreateVersionedRootSignatureDeserializer);
    LOAD_D3D12(D3D12EnableExperimentalFeatures);
    LOAD_D3D12(D3D12GetInterface);
    LOAD_D3D12(D3D12SerializeRootSignature);
    LOAD_D3D12(D3D12SerializeVersionedRootSignature);
    
    LOAD_DXGI(DXGIGetDebugInterface1);
    LOAD_DXGI(CreateDXGIFactory2);
    LOAD_DXGI(DXGIDeclareAdapterRemovalSupport);
    LOAD_DXGI(DXGIDisableVBlankVirtualization);
  } IERREND { }
  return IERRVAL;
}
