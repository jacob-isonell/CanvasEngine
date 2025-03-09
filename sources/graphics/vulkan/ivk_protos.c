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

#include "ivk_protos.h"

ICE_API ce_err ivk_load_protos(
  CE_IN  const VkInstanceCreateInfo* CE_RESTRICT info,
  CE_OUT ivk_protos*                 CE_RESTRICT out
) {
  ICE_ASSERT(info != NULL);
  ICE_ASSERT(out != NULL);
  
  *out = (ivk_protos) {0};
  IERRBEGIN {
    IERRDO(ce_lib_open(&out->libvulkan1, IVK_DLL_FILE, CE_LIB_FLAG_NONE));
    IERRDO(ce_lib_load(out->libvulkan1, "vkGetInstanceProcAddr", &out->vkGetInstanceProcAddr));
    
    printf(IASCII_CYAN 
      "Enabled layers :\n"
      "================\n"
    );
    for (size_t i = 0; i < info->enabledLayerCount; ++i) {
      printf(IASCII_CYAN "%zu : \"%s\"\n", (i + 1), info->ppEnabledLayerNames[i]);
    }
    if (info->enabledLayerCount == 0) {
      printf(IASCII_CYAN "\"NO LAYERS ENABLED\"\n");
    }
    
    printf(IASCII_CYAN 
      "\nEnabled Extensions :\n"
          "====================\n"
    );
    for (size_t i = 0; i < info->enabledExtensionCount; ++i) {
      printf(IASCII_CYAN "%zu : \"%s\"\n", (i + 1), info->ppEnabledExtensionNames[i]);
    }
    puts(IASCII_RESET);
    
  #define LOAD(name) out->name = (CONCAT(PFN_, name))out->vkGetInstanceProcAddr(NULL, #name)
    
    LOAD(vkEnumerateInstanceVersion);
    LOAD(vkEnumerateInstanceExtensionProperties);
    LOAD(vkEnumerateInstanceLayerProperties);
    LOAD(vkCreateInstance);
    
    IERRDO(ifrom_vk(out->vkCreateInstance(info, IVK_ALLOC, &out->instance)));
    
  #undef LOAD
  #define LOAD(name) out->name = (CONCAT(PFN_, name))out->vkGetInstanceProcAddr(out->instance, #name)
    LOAD(vkDestroyInstance);
    
  } IERREND {
    ce_lib_close(out->libvulkan1);
    *out = (ivk_protos) {0};
  }
  return IERRVAL;
}

ICE_API void ivk_unload_protos(
  CE_INOUT ivk_protos* CE_RESTRICT protos
) {
  ICE_ASSERT(protos != NULL);
  
  if (protos->vkDestroyInstance) {
    protos->vkDestroyInstance(protos->instance, IVK_ALLOC);
  }
  
  ce_lib_close(protos->libvulkan1);
  *protos = (ivk_protos) {0};
}
