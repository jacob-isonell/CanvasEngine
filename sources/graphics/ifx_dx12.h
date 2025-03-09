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

#ifndef IFX_DX12_H
#define IFX_DX12_H

#include "ifx_base.h"
#include <canvas/graphics.h>

#ifdef CANVAS_ENABLE_DIRECTX12

#include <dxgi1_6.h>
#include <dxgicommon.h>
#include <dxgidebug.h>
#include <d3dcommon.h>
#include <d3d12.h>
#include <d3d12sdklayers.h>
#include <d3d12shader.h>
#include "idx12_uuid.h"

CE_NAMESPACE_BEGIN

CE_NAMESPACE_END

#endif /* !CANVAS_ENABLE_DIRECTX12 */

#endif /* !IFX_DX12_H */
