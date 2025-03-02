#include "tests.h"

int main(void) {
  CHECK_SUCCESS(ce_init());
  
  ce_err e = CE_EOK;
  ce_alloc_t a = {0};
  CHECK_FAILURE(ce_set_alloc(a));
  
  void* p = ce_alloc_s(20, &e);
  CHECK(p != NULL && ce_success(e));
  CHECK_SUCCESS(ce_free(p));
  
  ce_shutdown();
  return 0;
}
