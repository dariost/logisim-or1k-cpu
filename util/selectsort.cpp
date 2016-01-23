#include "lib.hpp"

void swap(unsigned int* a, unsigned int* b);
unsigned int get_vector(char* _s, unsigned int* _v);

int main()
{
    char out1[] = "Input vector:  ";
    char out2[] = "Sorted vector: ";
    prints(out1);
    char* in = (char*)0x200000;
    scans(in);
    unsigned int* v = (unsigned int*)0x300000;
    unsigned int n = get_vector(in, v);
    prints(out2);
    for(unsigned int i = 0; i < n; i++)
    {
        unsigned int min_val = 4294967295, min_index = -1;
        for(unsigned int j = i; j < n; j++)
        {
            if(v[j] < min_val)
            {
                min_val = v[j];
                min_index = j;
            }
        }
        swap(&v[i], &v[min_index]);
        printu(v[i]);
        printc(' ');
    }
    printc('\n');
    return 0;
}

unsigned int get_vector(char* _s, unsigned int* _v)
{
    unsigned int tmp = 0;
    unsigned int size = 0;
    for(unsigned int i = 0; _s[i]; i++)
    {
        if(_s[i] >= 0 + '0' && _s[i] < 10 + '0')
        {
            tmp *= 10;
            tmp += _s[i] - '0';
        }
        else
        {
            _v[size++] = tmp;
            tmp = 0;
        }
    }
    _v[size++] = tmp;
    return size;
}

void swap(unsigned int* a, unsigned int* b)
{
    if(a == b)
        return;
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

