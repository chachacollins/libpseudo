#include <string.h>
#include "str.h"
#include "tgc.h"

void *mempcpy(void *dest, const void *src,size_t n);

string_t string_concat(tgc_t *gc, string_t *s1, string_t *s2)
{
    char* new_str = (char*)tgc_alloc(gc, sizeof(char) * (s1->len + s2->len + 1)); 
    *(char*)mempcpy(mempcpy(new_str, s1->str, s1->len), s2->str, s2->len) = '\0';
    return (string_t) {.str = new_str, .len = s1->len + s2->len};
}
