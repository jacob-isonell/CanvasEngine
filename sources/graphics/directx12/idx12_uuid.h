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

#ifndef IDX12_UUID_H
#define IDX12_UUID_H

#define IDX_UUIDOF(ptr) _Generic((ptr), \
  IDXGIAdapter*: &IID_IDXGIAdapter, \
  IDXGIAdapter1*: &IID_IDXGIAdapter1, \
  IDXGIAdapter2*: &IID_IDXGIAdapter2, \
  IDXGIAdapter3*: &IID_IDXGIAdapter3, \
  IDXGIAdapter4*: &IID_IDXGIAdapter4, \
  IDXGIDebug*: &IID_IDXGIDebug, \
  IDXGIDebug1*: &IID_IDXGIDebug1, \
  IDXGIDecodeSwapChain*: &IID_IDXGIDecodeSwapChain, \
  IDXGIDevice*: &IID_IDXGIDevice, \
  IDXGIDevice1*: &IID_IDXGIDevice1, \
  IDXGIDevice2*: &IID_IDXGIDevice2, \
  IDXGIDevice3*: &IID_IDXGIDevice3, \
  IDXGIDevice4*: &IID_IDXGIDevice4, \
  IDXGIDeviceSubObject*: &IID_IDXGIDeviceSubObject, \
  IDXGIDisplayControl*: &IID_IDXGIDisplayControl, \
  IDXGIFactory*: &IID_IDXGIFactory, \
  IDXGIFactory1*: &IID_IDXGIFactory1, \
  IDXGIFactory2*: &IID_IDXGIFactory2, \
  IDXGIFactory3*: &IID_IDXGIFactory3, \
  IDXGIFactory4*: &IID_IDXGIFactory4, \
  IDXGIFactory5*: &IID_IDXGIFactory5, \
  IDXGIFactory6*: &IID_IDXGIFactory6, \
  IDXGIFactory7*: &IID_IDXGIFactory7, \
  IDXGIFactoryMedia*: &IID_IDXGIFactoryMedia, \
  IDXGIInfoQueue*: &IID_IDXGIInfoQueue, \
  IDXGIKeyedMutex*: &IID_IDXGIKeyedMutex, \
  IDXGIObject*: &IID_IDXGIObject, \
  IDXGIOutput*: &IID_IDXGIOutput, \
  IDXGIOutput1*: &IID_IDXGIOutput1, \
  IDXGIOutput2*: &IID_IDXGIOutput2, \
  IDXGIOutput3*: &IID_IDXGIOutput3, \
  IDXGIOutput4*: &IID_IDXGIOutput4, \
  IDXGIOutput5*: &IID_IDXGIOutput5, \
  IDXGIOutput6*: &IID_IDXGIOutput6, \
  IDXGIOutputDuplication*: &IID_IDXGIOutputDuplication, \
  IDXGIResource*: &IID_IDXGIResource, \
  IDXGIResource1*: &IID_IDXGIResource1, \
  IDXGISurface*: &IID_IDXGISurface, \
  IDXGISurface1*: &IID_IDXGISurface1, \
  IDXGISurface2*: &IID_IDXGISurface2, \
  IDXGISwapChain*: &IID_IDXGISwapChain, \
  IDXGISwapChain1*: &IID_IDXGISwapChain1, \
  IDXGISwapChain2*: &IID_IDXGISwapChain2, \
  IDXGISwapChain3*: &IID_IDXGISwapChain3, \
  IDXGISwapChain4*: &IID_IDXGISwapChain4, \
  IDXGISwapChainMedia*: &IID_IDXGISwapChainMedia, \
  ID3D12CommandAllocator*: &IID_ID3D12CommandAllocator, \
  ID3D12CommandList*: &IID_ID3D12CommandList, \
  ID3D12CommandQueue*: &IID_ID3D12CommandQueue, \
  ID3D12CommandSignature*: &IID_ID3D12CommandSignature, \
  ID3D12DescriptorHeap*: &IID_ID3D12DescriptorHeap, \
  ID3D12Device*: &IID_ID3D12Device, \
  ID3D12Device1*: &IID_ID3D12Device1, \
  ID3D12Device2*: &IID_ID3D12Device2, \
  ID3D12Device3*: &IID_ID3D12Device3, \
  ID3D12Device4*: &IID_ID3D12Device4, \
  ID3D12Device5*: &IID_ID3D12Device5, \
  ID3D12Device6*: &IID_ID3D12Device6, \
  ID3D12Device7*: &IID_ID3D12Device7, \
  ID3D12Device8*: &IID_ID3D12Device8, \
  ID3D12Device9*: &IID_ID3D12Device9, \
  ID3D12Device10*: &IID_ID3D12Device10, \
  ID3D12Device11*: &IID_ID3D12Device11, \
  ID3D12Device12*: &IID_ID3D12Device12, \
  ID3D12Device13*: &IID_ID3D12Device13, \
  ID3D12Device14*: &IID_ID3D12Device14, \
  ID3D12DeviceChild*: &IID_ID3D12DeviceChild, \
  ID3D12DeviceRemovedExtendedData*: &IID_ID3D12DeviceRemovedExtendedData, \
  ID3D12DeviceRemovedExtendedDataSettings*: &IID_ID3D12DeviceRemovedExtendedDataSettings, \
  ID3D12Fence*: &IID_ID3D12Fence, \
  ID3D12Fence1*: &IID_ID3D12Fence1, \
  ID3D12GraphicsCommandList*: &IID_ID3D12GraphicsCommandList, \
  ID3D12GraphicsCommandList1*: &IID_ID3D12GraphicsCommandList1, \
  ID3D12GraphicsCommandList2*: &IID_ID3D12GraphicsCommandList2, \
  ID3D12GraphicsCommandList3*: &IID_ID3D12GraphicsCommandList3, \
  ID3D12GraphicsCommandList4*: &IID_ID3D12GraphicsCommandList4, \
  ID3D12GraphicsCommandList7*: &IID_ID3D12GraphicsCommandList7, \
  ID3D12Heap*: &IID_ID3D12Heap, \
  ID3D12LifetimeOwner*: &IID_ID3D12LifetimeOwner, \
  ID3D12LifetimeTracker*: &IID_ID3D12LifetimeTracker, \
  ID3D12MetaCommand*: &IID_ID3D12MetaCommand, \
  ID3D12Object*: &IID_ID3D12Object, \
  ID3D12Pageable*: &IID_ID3D12Pageable, \
  ID3D12PipelineLibrary*: &IID_ID3D12PipelineLibrary, \
  ID3D12PipelineLibrary1*: &IID_ID3D12PipelineLibrary1, \
  ID3D12PipelineState*: &IID_ID3D12PipelineState, \
  ID3D12QueryHeap*: &IID_ID3D12QueryHeap, \
  ID3D12Resource*: &IID_ID3D12Resource, \
  ID3D12RootSignature*: &IID_ID3D12RootSignature, \
  ID3D12RootSignatureDeserializer*: &IID_ID3D12RootSignatureDeserializer, \
  ID3D12SDKConfiguration*: &IID_ID3D12SDKConfiguration, \
  ID3D12ShaderCacheSession*: &IID_ID3D12ShaderCacheSession, \
  ID3D12StateObject*: &IID_ID3D12StateObject, \
  ID3D12StateObjectProperties*: &IID_ID3D12StateObjectProperties, \
  ID3D12Tools*: &IID_ID3D12Tools, \
  ID3D12VersionedRootSignatureDeserializer*: &IID_ID3D12VersionedRootSignatureDeserializer, \
  ID3D12VirtualizationGuestDevice*: &IID_ID3D12VirtualizationGuestDevice, \
  ID3D12Debug*: &IID_ID3D12Debug, \
  ID3D12Debug1*: &IID_ID3D12Debug1, \
  ID3D12Debug2*: &IID_ID3D12Debug2, \
  ID3D12Debug3*: &IID_ID3D12Debug3, \
  ID3D12Debug4*: &IID_ID3D12Debug4, \
  ID3D12Debug5*: &IID_ID3D12Debug5, \
  ID3D12Debug6*: &IID_ID3D12Debug6, \
  ID3D12DebugCommandList*: &IID_ID3D12DebugCommandList, \
  ID3D12DebugCommandList1*: &IID_ID3D12DebugCommandList1, \
  ID3D12DebugCommandQueue*: &IID_ID3D12DebugCommandQueue, \
  ID3D12DebugDevice*: &IID_ID3D12DebugDevice, \
  ID3D12DebugDevice1*: &IID_ID3D12DebugDevice1, \
  ID3D12InfoQueue*: &IID_ID3D12InfoQueue, \
  ID3D12SharingContract*: &IID_ID3D12SharingContract, \
  ID3D12FunctionParameterReflection*: &IID_ID3D12FunctionParameterReflection, \
  ID3D12FunctionReflection*: &IID_ID3D12FunctionReflection, \
  ID3D12LibraryReflection*: &IID_ID3D12LibraryReflection, \
  ID3D12ShaderReflection*: &IID_ID3D12ShaderReflection, \
  ID3D12ShaderReflectionConstantBuffer*: &IID_ID3D12ShaderReflectionConstantBuffer, \
  ID3D12ShaderReflectionType*: &IID_ID3D12ShaderReflectionType, \
  ID3D12ShaderReflectionVariable*: &IID_ID3D12ShaderReflectionVariable \
)

#endif /* !IDX12_UUID_H */
