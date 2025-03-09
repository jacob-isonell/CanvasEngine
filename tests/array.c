#include "tests.h"

int main(void) {
  ce_arr(int) arr = CE_ARRINIT;
  CHECK(arr == NULL);
  
  CHECK_SUCCESS(ce_arr_reserve(&arr, 7, sizeof(*arr)));
  CHECK(ce_arr_cap(arr) == 7);
  CHECK(ce_arr_size(arr) == 0);
  
  ce_arr_free(arr);
  arr = NULL;
  
  CHECK_SUCCESS(ce_arr_resize(&arr, 15, sizeof(*arr)));
  CHECK(ce_arr_cap(arr) == 15);
  CHECK(ce_arr_size(arr) == 15);
  
  ce_arr_free(arr);
  arr = NULL;
  return 0;
}
