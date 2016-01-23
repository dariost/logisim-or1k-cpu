#include "lib.hpp"

int main()
{
    printu(1);
    printc(' ');
    printu(1);
    printc(' ');
    unsigned int a = 1, b = 1, c = 2;
    while(b < 2147483647)
    {
        c = a + b;
        printu(c);
        printc(' ');
        a = b;
        b = c;
    }
    return 0;
}

