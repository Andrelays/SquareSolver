#include "header.h"

//#define _TX_ALLOW_TRACE 9
#define TEST

int main()
{
    #ifdef TEST
        test();
    #else
        release();
    #endif

    return 0;
}
