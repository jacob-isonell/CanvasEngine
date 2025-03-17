#include "tests.h"

int main(void) {
  ce_err e = CE_EOK;
  ce_alloc_t a = {0};
  CHECK_FAILURE(ce_set_alloc(a));
  
  void* p = ce_alloc_s(20, &e);
  CHECK(p != NULL && ce_success(e));
  ce_free(p);
  return 0;
}
