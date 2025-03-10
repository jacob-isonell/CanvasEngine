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

static void irelease_driver(
  CE_INOUT ce_render_driver* self
) {
  IDXGIFactory2* const fact = self->data.dx12->fact;
  fact->lpVtbl->Release(fact);
  
  ce_lib_close(self->data.dx12->pfn.libd3d12);
  ifree(self->data.dx12, sizeof(*(self->data.dx12)));
  *self = (ce_render_driver) {0};
}

static const ice_render_driver_vfp s_vfp = {
  .release = &irelease_driver,
  .fetch_gpu_devs = NULL,
  .get_gpu_dev = NULL
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

static ce_err s_load(idx12_protos* prot);

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
  
  ice_directx12_driver_data* data = NULL;
  IDXGIFactory2* fact = NULL;
  ce_lib* libd3d12 = NULL;
  ce_lib* libdxgi = NULL;
  
  IERRBEGIN {
    data = ialloc(sizeof(*data), &IERRVAL);
    driver->data.dx12 = data;
    IERRDO(IERRVAL);
    
    IERRDO(ce_lib_open(&libd3d12, "d3d12.dll", CE_LIB_FLAG_NONE));
    IERRDO(ce_lib_open(&libdxgi, "dxgi.dll", CE_LIB_FLAG_NONE));
    data->pfn.libd3d12 = libd3d12;
    data->pfn.libdxgi = libdxgi;
    
    IERRDO(s_load(&data->pfn));
    
    IERRDO(ifrom_hres(data->pfn.CreateDXGIFactory2(dxgifact_flags, IDX_UUIDOF(fact), (void**)&fact)));
    data->fact = fact;
    
    if (info->enable_debug) {
      s_enable_debinfo(&data->pfn);
    }
    
    const ice_render_driver_vfp* const addr = &s_vfp;
    memcpy(&driver->vfp, &addr, sizeof(addr));
  } IERREND {
    ce_lib_close(libdxgi);
    ce_lib_close(libd3d12);
    
    if (fact != NULL) {
      fact->lpVtbl->Release(fact);
    }
    
    ifree(data, sizeof(*data));
    *driver = (ce_render_driver) {0};
  }
  
  return IERRVAL;
}

static ce_err s_load(idx12_protos* prot) {
#define LOAD_DXGI(name) IERRDO(ce_lib_load(prot->libd3d12, #name, (void*)&prot->name))
#define LOAD_D3D12(name) IERRDO(ce_lib_load(prot->libd3d12, #name, (void*)&prot->name))
  
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
