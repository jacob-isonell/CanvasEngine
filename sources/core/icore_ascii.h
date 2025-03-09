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

#ifndef ICORE_ASCII_H
#define ICORE_ASCII_H

#define IASCII_ESCAPE "\x1B"
#define IASCII_BLACK         IASCII_ESCAPE "[0;30m"
#define IASCII_RED           IASCII_ESCAPE "[0;31m"
#define IASCII_GREEN         IASCII_ESCAPE "[0;32m"
#define IASCII_YELLOW        IASCII_ESCAPE "[0;33m"
#define IASCII_BLUE          IASCII_ESCAPE "[0;34m"
#define IASCII_PURPLE        IASCII_ESCAPE "[0;35m"
#define IASCII_CYAN          IASCII_ESCAPE "[0;36m"
#define IASCII_WHITE         IASCII_ESCAPE "[0;37m"
#define IASCII_BOLD_BLACK    IASCII_ESCAPE "[1;30m"
#define IASCII_BOLD_RED      IASCII_ESCAPE "[1;31m"
#define IASCII_BOLD_GREEN    IASCII_ESCAPE "[1;32m"
#define IASCII_BOLD_YELLOW   IASCII_ESCAPE "[1;33m"
#define IASCII_BOLD_BLUE     IASCII_ESCAPE "[1;34m"
#define IASCII_BOLD_PURPLE   IASCII_ESCAPE "[1;35m"
#define IASCII_BOLD_CYAN     IASCII_ESCAPE "[1;36m"
#define IASCII_BOLD_WHITE    IASCII_ESCAPE "[1;37m"
#define IASCII_UL_BLACK      IASCII_ESCAPE "[4;30m"
#define IASCII_UL_RED        IASCII_ESCAPE "[4;31m"
#define IASCII_UL_GREEN      IASCII_ESCAPE "[4;32m"
#define IASCII_UL_YELLOW     IASCII_ESCAPE "[4;33m"
#define IASCII_UL_BLUE       IASCII_ESCAPE "[4;34m"
#define IASCII_UL_PURPLE     IASCII_ESCAPE "[4;35m"
#define IASCII_UL_CYAN       IASCII_ESCAPE "[4;36m"
#define IASCII_UL_WHITE      IASCII_ESCAPE "[4;37m"
#define IASCII_BG_BLACK      IASCII_ESCAPE "[40m"
#define IASCII_BG_RED        IASCII_ESCAPE "[41m"
#define IASCII_BG_GREEN      IASCII_ESCAPE "[42m"
#define IASCII_BG_YELLOW     IASCII_ESCAPE "[43m"
#define IASCII_BG_BLUE       IASCII_ESCAPE "[44m"
#define IASCII_BG_PURPLE     IASCII_ESCAPE "[45m"
#define IASCII_BG_CYAN       IASCII_ESCAPE "[46m"
#define IASCII_BG_WHITE      IASCII_ESCAPE "[47m"
#define IASCII_HI_BLACK      IASCII_ESCAPE "[0;90m"
#define IASCII_HI_RED        IASCII_ESCAPE "[0;91m"
#define IASCII_HI_GREEN      IASCII_ESCAPE "[0;92m"
#define IASCII_HI_YELLOW     IASCII_ESCAPE "[0;93m"
#define IASCII_HI_BLUE       IASCII_ESCAPE "[0;94m"
#define IASCII_HI_PURPLE     IASCII_ESCAPE "[0;95m"
#define IASCII_HI_CYAN       IASCII_ESCAPE "[0;96m"
#define IASCII_HI_WHITE      IASCII_ESCAPE "[0;97m"
#define IASCII_HIBOLD_BLACK  IASCII_ESCAPE "[1;90m"
#define IASCII_HIBOLD_RED    IASCII_ESCAPE "[1;91m"
#define IASCII_HIBOLD_GREEN  IASCII_ESCAPE "[1;92m"
#define IASCII_HIBOLD_YELLOW IASCII_ESCAPE "[1;93m"
#define IASCII_HIBOLD_BLUE   IASCII_ESCAPE "[1;94m"
#define IASCII_HIBOLD_PURPLE IASCII_ESCAPE "[1;95m"
#define IASCII_HIBOLD_CYAN   IASCII_ESCAPE "[1;96m"
#define IASCII_HIBOLD_WHITE  IASCII_ESCAPE "[1;97m"
#define IASCII_HIBG_BLACK    IASCII_ESCAPE "[0;100m"
#define IASCII_HIBG_RED      IASCII_ESCAPE "[0;101m"
#define IASCII_HIBG_GREEN    IASCII_ESCAPE "[0;102m"
#define IASCII_HIBG_YELLOW   IASCII_ESCAPE "[0;103m"
#define IASCII_HIBG_BLUE     IASCII_ESCAPE "[0;104m"
#define IASCII_HIBG_PURPLE   IASCII_ESCAPE "[0;105m"
#define IASCII_HIBG_CYAN     IASCII_ESCAPE "[0;106m"
#define IASCII_HIBG_WHITE    IASCII_ESCAPE "[0;107m"
#define IASCII_RESET         IASCII_ESCAPE "[0m"

#endif /* !ICORE_ASCII_H */
