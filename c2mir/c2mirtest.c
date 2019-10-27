#include "c2mir.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void *import_resolver(const char *name) {
  if (strcmp(name, "printf") == 0) {
    return printf;
  }
  return NULL;
}

int main(int argc, const char *argv[]) {

  const char *code1 = "extern int printf(const char *, ...);\n"
                      "int f1(void) { printf(\"hello world from f1\\n\"); return 0; }\n";
  const char *code2 = "extern int printf(const char *, ...);\n"
                      "int f2(void) { printf(\"hello world from f2\\n\"); return 0; }\n";

  int (*fp1)() = MIR_compile_C_module(code1, "f1", import_resolver);
  int (*fp2)() = MIR_compile_C_module(code2, "f2", import_resolver);

  fp1();
  fp2();

  return 0;
}