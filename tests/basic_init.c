#include "tests.h"

int main(void) {
  CHECK_SUCCESS(ce_init());
  
  {
    ce_core op;
    CHECK_FAILURE(ce_core_set(NULL));
    CHECK_FAILURE(ce_core_set(&op));
  }
#ifdef CANVAS_GRAPHICS
  {
    ce_graphics op;
    CHECK_FAILURE(ce_graphics_set(NULL));
    CHECK_FAILURE(ce_graphics_set(&op));
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
  
  ce_shutdown();
  return 0;
}
