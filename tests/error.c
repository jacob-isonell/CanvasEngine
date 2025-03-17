#include "tests.h"

int main(void) {
  CHECK(ce_success(CE_EOK) == cetrue);
  CHECK(ce_success(0) == cetrue);
  CHECK(ce_success(1) != cetrue);
  CHECK(ce_failure(CE_EOK) != cetrue);
  CHECK(ce_failure(0) != cetrue);
  CHECK(ce_failure(1) == cetrue);
  return 0;
}
