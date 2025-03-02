#include "tests.h"

int main(void) {
  {
    ce_core op;
    op.app_name = "CanvasTest Advance Init";
    op.app_version = CE_CURRVER;
    op.engine_name = "CanvasEngine";
    op.engine_version = CE_CURRVER;
    CHECK_SUCCESS(ce_core_set(&op));
  }
#ifdef CANVAS_GRAPHICS
  {
    ce_graphics op;
    CHECK_SUCCESS(ce_graphics_set(&op));
  }
#endif /* !CANVAS_GRAPHICS */
#ifdef CANVAS_AUDIO
  {
    
  }
#endif /* !CANVAS_AUDIO */
#ifdef CANVAS_NETWORK
  {
    
  }
#endif /* !CANVAS_NETWORK */
  
  CHECK_SUCCESS(ce_init());
  
  ce_shutdown();
  return 0;
}
