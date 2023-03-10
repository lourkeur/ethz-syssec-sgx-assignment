#include "Enclave.h"
#include "Enclave_t.h" /* ocalls */

#include <stdarg.h>
#include <stdio.h> /* vsnprintf */

int logf(const char *fmt, ...) {
  char buf[BUFSIZ] = {'\0'};
  va_list ap;
  va_start(ap, fmt);
  vsnprintf(buf, BUFSIZ, fmt, ap);
  va_end(ap);
  ocall_elog(buf);
  return (int)strnlen(buf, BUFSIZ - 1) + 1;
};
