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

#ifndef CANVAS_AUDIO_AUDIO_H
#define CANVAS_AUDIO_AUDIO_H

#include <canvas/core/error.h>

#ifndef CANVAS_AUDIO
#error the audio module for CanvasEngine has been disabled
#endif

CE_NAMESPACE_BEGIN

/**
 * @todo
 * Audio APIS to support/consider:
 * 
 * | ------------- | --------- | -------------- | -------------------------------------------------------------------------------------------------------------------------------- |
 * | API           | Languages | Platforms      | Sources/Documentations                                                                                                           |
 * | ============= | ========= | ============== | ================================================================================================================================ |
 * | JACK          | C         | Win32, Linux   | https://jackaudio.org/                                                                                                           |
 * | JACK2         | C++       | Win32, Linux   | https://github.com/jackaudio/jack2                                                                                               |
 * | PulseAudio    |           | Linux          | https://www.freedesktop.org/wiki/Software/PulseAudio/                                                                            |
 * | ALSA          |           | Linux          | https://www.alsa-project.org/wiki/Main_Page                                                                                      |
 * | CoreAudio     |           | MacOS          | https://developer.apple.com/library/archive/documentation/MusicAudio/Conceptual/CoreAudioOverview/Introduction/Introduction.html |
 * | XAudio2       | C/C++     | Win32          | https://learn.microsoft.com/en-us/windows/win32/xaudio2                                                                          |
 * | PortAudio     |           | Cross-platform | https://www.portaudio.com/                                                                                                       |
 * | libsoundio    |           | Cross-platform | https://github.com/andrewrk/libsoundio                                                                                           |
 * | CoreAudioAPIS | C         | Win32          | https://learn.microsoft.com/en-us/windows/win32/api/_coreaudio/                                                                  |
 * | WASAPI        | C         | Win32          | https://learn.microsoft.com/en-us/windows/win32/coreaudio/wasapi                                                                 |
 * | ------------- | --------- | -------------- | -------------------------------------------------------------------------------------------------------------------------------- |
 * 
 * JACK1 is C while JACK2 is C++, but JACK2 is suppose to not be as restrictive as JACK1
 * 
 */

CE_NAMESPACE_END

#endif /* !CANVAS_AUDIO_AUDIO_H */
