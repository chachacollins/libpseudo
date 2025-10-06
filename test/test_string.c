#include <assert.h>
#include "pseudo.h"

static tgc_t gc;

int main(int argc, char** argv)
{
    (void)argv;
    tgc_start(&gc, &argc);
    string_t str1 = StrLit("Hello");
    string_t str2 = StrLit(" World\n");
    assert(!strcmp(string_concat(&gc, &str1, &str2).str, "Hello World"));
    tgc_stop(&gc);
}
