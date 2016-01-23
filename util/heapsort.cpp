#include "lib.hpp"

#define parent(x) ((x - 1) / 2)
#define child1(x) ((x * 2) + 1)
#define child2(x) ((x * 2) + 2)

void swap(unsigned int* a, unsigned int* b);
unsigned int get_vector(char* _s, unsigned int* _v);
void heap_bu(unsigned int* v, unsigned int node);
void heap_td(unsigned int* v, unsigned int n, unsigned int node = 0);

int main()
{
    char out1[] = "Input vector:  ";
    char out2[] = "Sorted vector: ";
    prints(out1);
    char* in = (char*)0x200000;
    scans(in);
    unsigned int* v = (unsigned int*)0x300000;
    unsigned int n = get_vector(in, v);
    unsigned int n2 = n;
    prints(out2);
    for(unsigned int i = 0; i < n; i++)
        heap_bu(v, i);
    for(unsigned int i = 0; i < n; i++)
    {
        n2--;
        swap(&v[0], &v[n2]);
        printu(v[n2]);
        printc(' ');
        heap_td(v, n2);
    }
    printc('\n');
    return 0;
}

void heap_td(unsigned int* v, unsigned int n, unsigned int node)
{
    if(child1(node) >= n)
        return;
    if(child2(node) >= n)
    {
        if(v[node] > v[child1(node)])
        {
            swap(&v[node], &v[child1(node)]);
            heap_td(v, n, child1(node));
        }
        return;
    }
    unsigned int min_index = child1(node);
    if(v[child2(node)] < v[child1(node)])
        min_index += 1;
    if(v[node] > v[min_index])
    {
        swap(&v[node], &v[min_index]);
        heap_td(v, n, min_index);
    }
}

void heap_bu(unsigned int* v, unsigned int node)
{
    if(!node)
        return;
    if(v[parent(node)] <= v[node])
        return;
    swap(&v[node], &v[parent(node)]);
    heap_bu(v, parent(node));
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

