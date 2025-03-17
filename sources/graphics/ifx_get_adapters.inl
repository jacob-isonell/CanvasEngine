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

#ifndef IFX_GPU_ADAPTER_TYPE
#error IFX_GPU_ADAPTER_TYPE not defined
#endif /* !IFX_GPU_ADAPTER_TYPE */

#ifndef IFX_GPU_ADAPTER_VAR
#error IFX_GPU_ADAPTER_VAR not defined
#endif /* !IFX_GPU_ADAPTER_TYPE */
 
static ce_err iget_gpu_adapters(
  CE_IN      const ce_render_driver* CE_RESTRICT self,
  CE_OUT     ce_gpu_adapter*         CE_RESTRICT buffer,
             size_t                              bufflen,
             size_t                              index,
  CE_OUT_OPT size_t*                 CE_RESTRICT out_len
) {
  ce_arr(IFX_GPU_ADAPTER_TYPE) adapters = self->data.IFX_GPU_ADAPTER_VAR->gpu_adapters;
  const size_t arrlen = ce_arr_size(adapters);
  
  if (arrlen == 0) {
    /* most likely fetch_gpu_adapters hasn't been called before. */
    IDEBWARN("No GPU adapters stored, did you forget to call \"fetch_gpu_adapters\"?\n");
    return CE_ENODATA;
  }
  
  if (buffer == NULL || bufflen == 0) {
    if (out_len == NULL) {
      return CE_EINVAL;
    }
    
    *out_len = arrlen;
    return CE_EOK;
  }
  
  if (arrlen <= index) {
    index = arrlen - 1;
  }
  
  const size_t max_arrlen = arrlen - index;
  
  const size_t maxlen = bufflen < max_arrlen
    ? bufflen
    : max_arrlen;
  
  for (size_t i = 0; i < maxlen; ++i) {
    buffer[i].IFX_GPU_ADAPTER_VAR = (adapters + index + i);
  }
  
  if (out_len) {
    *out_len = maxlen;
  }
  return CE_EOK;
}
