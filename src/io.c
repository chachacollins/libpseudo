#include "io.h"

extern inline int print_int(int x) 
{
    return printf("%d", x);
}

extern inline int print_uint(unsigned int x)
{
    return printf("%u", x);
}

extern inline int print_str(const string_t *const str)
{
    return printf("%s", str->str);
}
