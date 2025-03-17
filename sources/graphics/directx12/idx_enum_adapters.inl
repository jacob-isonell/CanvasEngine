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

#ifndef IDX_ENUMFUNC_NAME
#error IDX_ENUMFUNC not defined
#endif /* !IDX_ENUMFUNC */

#ifndef IDX_ENUMFACT
#error IDX_ENUMFACT not defined
#endif

#ifndef IDX_ENUMFUNC
#error IDX_ENUMFUNC not defined
#endif

static ce_err IDX_ENUMFUNC_NAME(
  CE_INOUT ce_arr(ice_gpu_adapter_dx12)* CE_RESTRICT adapters,
  CE_INOUT IDX_ENUMFACT*                 CE_RESTRICT fact,
           DXGI_GPU_PREFERENCE                       order_pref
) {
  (void)order_pref;
  ICE_ASSERT(adapters != NULL);
  
  UINT i = 0;
  HRESULT hcode;
  
  const size_t start_len = *adapters ? ce_arr_size(*adapters) : 0;
  
  for (;; ++i) {
    const ce_err e = s_grow_adapters_arr(adapters);
    if (ce_failure(e)) {
      return e;
    }
    
    /* The resizing of the buffer is handled in the code above.
      * If theres already space in the buffer then resizing it
      * will just set it's length. So no errors can occur.
      */
    (void)ce_arr_resize(adapters, i + 1, sizeof(**adapters));
    
    ice_gpu_adapter_dx12* const out = (*adapters) + start_len + i;
    *out = (ice_gpu_adapter_dx12) {0};
    
    hcode = IDX_ENUMFUNC(fact, i, order_pref, IDX_UUIDOF(out->adap), (void**)&out->adap);
    if (FAILED(hcode)) {
      /* Delete the last adapter. */
      (void)ce_arr_resize(adapters, i, sizeof(**adapters));
      
      return hcode == DXGI_ERROR_NOT_FOUND
        ? CE_EOK
        : ifrom_hres(hcode);
    }
  }
}
