#include "lib.hpp"

int main()
{
    unsigned int* p = (unsigned int*)4;
    unsigned int a = 5;
    printu(2);
    printc(' ');
    printu(3);
    printc(' ');
    while(true)
    {
        bool prime = true;
        for(unsigned int i = 3; i < div(a, 2) + 1; i += 2)
        {
            if(mod(a, i) == 0)
            {
                prime = false;
                break;
            }
        }
        if(prime)
        {
            printu(a);
            printc(' ');
        }
        a += 2;
    }
    return 0;
}
