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

#ifndef CANVAS_INPUT_INPUT_H
#define CANVAS_INPUT_INPUT_H

#include <canvas/core/error.h>

#ifndef CANVAS_INPUT
#error the input module for CanvasEngine has been disabled
#endif

CE_NAMESPACE_BEGIN

/**
 * @todo
 * Input APIS to support/consider:
 * 
 * | ---------------- | --------- | ----------- | ------------------------------------------------------------------------------------------------------------------------- |
 * | API              | Languages | Platforms   | Sources/Documentations                                                                                                    |
 * | ================ | ========= | =========== | ========================================================================================================================= |
 * | Steam Networking | C++       | Any         | https://partner.steamgames.com/doc/features/multiplayer/networking https://github.com/ValveSoftware/GameNetworkingSockets |
 * | nng              | C         | Any         | https://github.com/nanomsg/nng                                                                                            |
 * | ---------------- | --------- | ----------- | ------------------------------------------------------------------------------------------------------------------------- |
 * 
 * A list of C/C++ network APIs: https://stackoverflow.com/a/118968
 */

CE_NAMESPACE_END

#endif /* !CANVAS_INPUT_INPUT_H */
