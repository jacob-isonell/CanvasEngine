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

#ifndef IDX12_PROTOS_H
#define IDX12_PROTOS_H

#include "ifx_dx12.h"
#include <canvas/core/library.h>

typedef HRESULT (WINAPI* IPFN_D3D12CreateDevice)(
  CE_IN_OPT  IUnknown*         pAdapter,
             D3D_FEATURE_LEVEL MinimumFeatureLevel,
  CE_IN      REFIID            riid,
  CE_OUT_OPT void**            ppDevice
);

typedef HRESULT (WINAPI* IPFN_D3D12CreateRootSignatureDeserializer)(
  CE_IN  LPCVOID pSrcData,
  CE_IN  SIZE_T  SrcDataSizeInBytes,
  CE_IN  REFIID  pRootSignatureDeserializerInterface,
  CE_OUT void**  ppRootSignatureDeserializer
);

typedef HRESULT (WINAPI* IPFN_D3D12CreateVersionedRootSignatureDeserializer)(
  CE_IN  LPCVOID pSrcData,
  CE_IN  SIZE_T  SrcDataSizeInBytes,
  CE_IN  REFIID  pRootSignatureDeserializerInterface,
  CE_OUT void**  ppRootSignatureDeserializer
);

typedef HRESULT (WINAPI* IPFN_D3D12EnableExperimentalFeatures)(
        UINT       NumFeatures,
  CE_IN const IID* pIIDs,
  CE_IN void*      pConfigurationStructs,
  CE_IN UINT*      pConfigurationStructSizes
);

typedef HRESULT (WINAPI* IPFN_D3D12GetInterface)(
  CE_IN  REFCLSID rclsid,
  CE_IN  REFIID   riid,
  CE_OUT void**   ppvDebug
);

typedef HRESULT (WINAPI* IPFN_D3D12SerializeRootSignature)(
  CE_IN            const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
  CE_IN            D3D_ROOT_SIGNATURE_VERSION       Version,
  CE_OUT           ID3DBlob**                       ppBlob,
  CE_OUT_OPT ID3DBlob** ppErrorBlob
);

typedef HRESULT (WINAPI* IPFN_D3D12SerializeVersionedRootSignature)(
  CE_IN      const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
  CE_OUT     ID3DBlob**                                 ppBlob,
  CE_OUT_OPT ID3DBlob**                                 ppErrorBlob
);

typedef HRESULT (WINAPI* IPFN_DXGIGetDebugInterface1)(
         UINT   Flags,
  CE_IN  REFIID riid,
  CE_OUT void** pDebug
);

typedef HRESULT (WINAPI* IPFN_CreateDXGIFactory2)(
         UINT   Flags,
  CE_IN  REFIID riid,
  CE_OUT void** ppFactory
);

typedef HRESULT (WINAPI *IPFN_DXGIDeclareAdapterRemovalSupport)(void);
typedef HRESULT (WINAPI *IPFN_DXGIDisableVBlankVirtualization)(void);

typedef struct idx12_protos {
  ce_lib* libd3d12;
  ce_lib* libdxgi;
  
  IPFN_D3D12CreateDevice                             D3D12CreateDevice;
  IPFN_D3D12CreateRootSignatureDeserializer          D3D12CreateRootSignatureDeserializer;
  IPFN_D3D12CreateVersionedRootSignatureDeserializer D3D12CreateVersionedRootSignatureDeserializer;
  IPFN_D3D12EnableExperimentalFeatures               D3D12EnableExperimentalFeatures;
  IPFN_D3D12GetInterface                             D3D12GetInterface;
  IPFN_D3D12SerializeRootSignature                   D3D12SerializeRootSignature;
  IPFN_D3D12SerializeVersionedRootSignature          D3D12SerializeVersionedRootSignature;
  
  IPFN_DXGIGetDebugInterface1           DXGIGetDebugInterface1;
  IPFN_CreateDXGIFactory2               CreateDXGIFactory2;
  IPFN_DXGIDeclareAdapterRemovalSupport DXGIDeclareAdapterRemovalSupport;
  IPFN_DXGIDisableVBlankVirtualization  DXGIDisableVBlankVirtualization;
  
} idx12_protos;

struct ice_directx12_driver_data {
  idx12_protos pfn;
  IDXGIFactory2* fact;
};

#endif /* !IDX12_PROTOS_H */
