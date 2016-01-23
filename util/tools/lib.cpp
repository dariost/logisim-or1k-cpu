#include "lib.hpp"

char* _ibp = (char*)0x00100004;

unsigned int div(unsigned int a, unsigned int b)
{
    unsigned int c;
    __asm__ volatile (
        "l.divu %0, %1, %2\n"
        :   "=r"(c)
        :   "r"(a), "r"(b)
    );
    return c;
}

unsigned int mod(unsigned int a, unsigned int b)
{
    return a - div(a, b) * b;
}

void printc(char c)
{
    *(char*)0x100000 = c;
}

void prints(const char* s)
{
    unsigned int i = 0;
    while(s[i])
        printc(s[i++]);
}

void printu(unsigned int n)
{
    if(n < 10)
    {
        printc(n + 48);
        return;
    }
    printu(div(n, 10));
    printc(mod(n, 10) + 48);
}

char scanc()
{
    while(!(*_ibp));
    char tmp = *_ibp;
    _ibp++;
    return tmp;
}

unsigned int scans(char* _b, bool _echo)
{
    unsigned int _n = 0;
    while(true)
    {
        char tmp = scanc();
        if(_echo)
            printc(tmp);
        if(tmp == '\n')
            break;
        _b[_n] = tmp;
        _n++;
    }
    _b[_n] = '\0';
    return _n;
}
