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

#include "icore_base.h"
#include <canvas/core/library.h>

#if CANVAS_PLATFORM_UNIX
#include <dlfcn.h>
#endif

CE_API ce_err ce_lib_open(struct ce_lib** handle, const char* filepath, ce_lib_flags flags) {
#if CANVAS_PLATFORM_WINDOWS
	(void)flags;
	const HMODULE mod = LoadLibraryExA(filepath, NULL, 0);
	if (mod == NULL) {
		return CE_EFAULT;
	}
	memcpy(handle, &mod, sizeof(mod));
	return CE_EOK;
#elif CANVAS_PLATFORM_UNIX
	/* dlopen(); */
	void* const mod = dlopen(filepath, RTLD_NOW);
	if (mod != NULL) {
		memcpy(handle, mod, sizeof(mod));
		return CE_EOK;
	}
	
#if CANVAS_DEBUG
	fprintf(stderr, "dlclose failed (\"%s\")\n", dlerror());
#endif
	
	return CE_ENOENT;
#endif
}

CE_API ce_err ce_lib_wopen(struct ce_lib** handle, const wchar_t* filepath, ce_lib_flags flags) {
#if CANVAS_PLATFORM_WINDOWS
	(void)flags;
	const HMODULE hmod = LoadLibraryExW(filepath, NULL, 0);
	if (hmod == NULL) {
		return CE_EFAULT;
	}
	memcpy(handle, &hmod, sizeof(hmod));
	return CE_EOK;
#elif CANVAS_PLATFORM_UNIX
	/* dlopen(); */
	ICE_NOIMPL();
#endif
}

CE_API ce_err ce_lib_load(struct ce_lib* handle, const char* name, void* out) {
	if (handle == NULL || name == NULL || out == NULL) {
		return CE_EINVAL;
	}
#if CANVAS_PLATFORM_WINDOWS
	ICE_NOIMPL();
	// GetProcAddress();
#elif CANVAS_PLATFORM_UNIX
	(void)dlerror();
	void* const p = dlsym((void*)handle, name);
	const char* const errstr = dlerror();
	if (errstr == NULL) {
		memcpy(out, &p, sizeof(p));
		return CE_EOK;
	}
	
#if CANVAS_DEBUG
	fprintf(stderr, "dlclose failed (\"%s\")\n", errstr);
#endif
	
	return CE_ENOENT;
#endif
}

CE_API void ce_lib_close(struct ce_lib* handle) {
	if (handle == NULL) {
		return;
	}
	
#if CANVAS_PLATFORM_WINDOWS
	FreeLibrary((HMODULE)handle);
#elif CANVAS_PLATFORM_UNIX
#if CANVAS_DEBUG
	if (dlclose(handle) != 0) {
		fprintf(stderr, "dlclose failed (\"%s\")\n", dlerror());
	}
#else
	dlclose(handle);
#endif
#endif
}
