#include "header.h"
#define TEST

int main (void)
{
    #ifdef TEST
        test();
    #else
        release();
    #endif

    return 0;
}
