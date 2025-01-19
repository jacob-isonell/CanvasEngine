<h1 align="center">CanvasEngine</h1>
<p align="center">A game engine framework written in C++20
	<br />
	&#x2022;
	<a style="width: 100%; text-align: center" href="https://github.com/lTechno/CanvasEngineDev/labels/bug">Report Bug</a>
	&#x2022;
	<a style="width: 100%; text-align: center" href="https://github.com/lTechno/CanvasEngineDev/labels/enhancement">Request Feature</a>
	&#x2022;
</p>

<details>
	<summary>Table of Contents</summary>
	<ul>
		<li>
			<a href="#about-the-project">About The Project</a>
			<ul><li><a href="#third-party-libraries">Third-party Libraries</a></li></ul>
		</li>
		<li>
			<a href="#getting-started">Getting Started</a>
			<ul>
				<li><a href="#prerequisites">Prerequisites</a></li>
				<li><a href="#build">Build</a></li>
				<li><a href="#usage">Usage</a></li>
			</ul>
		</li>
		<li>
			<a href="#license">License</a>
		</li>
	</ul>
</details>

## About The Project

CanvasEngine is a game engine framework written in C++20<br/>
Support Windows and Linux platforms.

### Build requirements

* CMake
* C++20 compiler (GCC, Clang, MSVC)
* VulkanSDK (Optional, required for graphics)
* WinSDK (Windows)
* GTK (Linux)
* PkgConfig (Linux)

### Dependencies Libraries

CanvasEngine is built with these third party libraries:

 * [VulkanAPI](https://vulkan.lunarg.com/) [![License](https://img.shields.io/badge/License-N/A-red.svg)](https://vulkan.lunarg.com/license)
 * GTK (Unix platforms)
 * PkgConfig (Unix platforms)
 * CMake (>= 3.30.0)
 <!-- * [GLFW](https://github.com/glfw/glfw/tree/7b6aead9fb88b3623e3b3725ebb42670cbe4c579) [![License](https://img.shields.io/badge/License-N/A-red.svg)](https://github.com/glfw/glfw/blob/7b6aead9fb88b3623e3b3725ebb42670cbe4c579/LICENSE.md) -->
 <!-- * [cpptrace](https://github.com/jeremy-rifkin/cpptrace/tree/0742b42dadaac62436cb226a7d084738a8f82d1a) [![License](https://img.shields.io/badge/License-N/A-red.svg)](https://github.com/jeremy-rifkin/cpptrace/blob/0742b42dadaac62436cb226a7d084738a8f82d1a/LICENSE) -->

## Getting Started

### Prerequisites

CanvasEngine has been tested on GCC, Clang and MSVC under Windows 11 and Linux on x86_64. <br />
You need CMake installed to build and configure the porject. <br />
The currently supported compilers are msvc, gcc and clang.

### Build

<!-- Checkout [building.md](docs/building.md) on how to build CanvasEngine -->
CanvasEngine uses CMake as its build system so building it is as simple as configuring the project with `cmake -S ./ -B build` and then building it with `cmake --build build`.
The following configuration options control the behaviour of CanvasEngine and what components gets built.

 * `CANVAS_LIBRARY_KIND (string)`: Determines the library type to build. Setting this to `SHARED` produces a shared library file, Setting this to `STATIC` produces a static library file. If left empty then `BUILD_SHARED_LIBS` is used to determine the library type to produce.
 * `CANVAS_GRAPHICS (boolean)`: Builds the graphics component.
 * `CANVAS_GRAPHICS_SUPPORT_X11 (boolean)`: Enables support for X11 library on linux.
 * `CANVAS_GRAPHICS_SUPPORT_WAYLAND (boolean)`: Enables support for Wayland library on Linux.
 * `CANVAS_GRAPHICS_ENABLE_VULKAN (boolean)`: Enables support for the VulkanAPI (requires the VulkanSDK to be installed).
 * `ICANVAS_DEVMODE (boolean)`: This is enables extra warnings and sanitizers for development purpouses, this should be left disabled when consuming this library.

### Usage

To get started using CanvasEngine, simple include the `canvas.hpp` header.
This header will automatically include all other headers needed to use CanvasEngine.

### Development

TODO: write about development plans here.

## License

Distributed under the GNU GPLv3 License. See `LICENSE` for more information.
