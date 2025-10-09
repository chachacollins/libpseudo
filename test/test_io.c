#include <pseudo.h>
#include <assert.h>

int main(void) 
{
    int pr1 = print_uint(10);
    assert(pr1 == 2);
    int pr2 = print_int(10);
    assert(pr2 == 2);
    int pr3 = print_str(&StrLit("Hello"));
    assert(pr3 == 5);
}
