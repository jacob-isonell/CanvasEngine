# Include Macros

Certain header files uses macro defines to change their behaviour

#### CANVAS_SKIP_COMPILER_CHECKS ([`canvas/core/base.h`](@ref canvas/core/base.h))
CanvasEngine performs checks during compile time to determine
if the compiler has all the nessecairy features required.
Defining this macro disables these checks and it's up to the programming
to ensure the compiler is able to compile the CanvasEngine library.

#### CANVAS_EXPOSE_VULKAN ([`canvas/graphics/graphics.h`](@ref canvas/graphics/graphics.h))
Exposes native access to VulkanAPI objects used by CanvasEngine. This requires manually including the VulkanAPI headers before including the CanvasEngine headers.

#### CANVAS_EXPOSE_WAYLAND ([`canvas/graphics/graphics.h`](@ref canvas/graphics/graphics.h))
Exposes native access to Wayland objects used by CanvasEngine. This requires manually including the Wayland headers before including the CanvasEngine headers.

#### CANVAS_EXPOSE_X11 ([`canvas/graphics/graphics.h`](@ref canvas/graphics/graphics.h))
Exposes native access to Xlib objects used by CanvasEngine. This requires manually including the Xlib headers before including the CanvasEngine headers.
