#ifndef MIR_C2MIR_H
#define MIR_C2MIR_H

extern void *MIR_compile_C_module(const char *inputbuffer, const char *func_name, void *(Import_resolver_func)(const char *name));

#endif

