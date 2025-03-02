#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <canvas.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int test(void);
int main(void) {
  ce_disable_debug_logs();
  return test();
}

#define main(...) test(void)

CE_INLINE
void s_check(cebool cond, const char* file, unsigned int line) {
  if (cond) {
    return;
  }
  
  fprintf(stderr, "check failed at %s:%u\n", file, line);
  exit(EXIT_FAILURE);
}

#define CHECK(expr) (s_check(!!(expr), __FILE__, __LINE__))
#define CHECK_SUCCESS(expr) CHECK(ce_success(expr))
#define CHECK_FAILURE(expr) CHECK(ce_failure(expr))
