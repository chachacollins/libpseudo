#ifndef STRINGS_H
#define STRINGS_H
#include "tgc.h"

typedef struct {
    char* str;
    size_t len;
} string_t;

#define StrLit(s) (string_t) {s, sizeof(s)-1}

string_t string_concat(tgc_t *gc, string_t *s1, string_t *s2);

#endif
