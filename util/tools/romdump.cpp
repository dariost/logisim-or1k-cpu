#include <cstdio>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    assert(argc == 2);
    FILE* fin = fopen(argv[1], "rb");
    assert(fin);
    string f;
    f = argv[1];
    f += ".rom";
    FILE* fout = fopen(f.c_str(), "w");
    assert(fout);
    fprintf(fout, "v2.0 raw\n");
    int c = 0;
    vector<unsigned char> v;
    while(!feof(fin))
    {
        unsigned char tmp;
        if(!fread(&tmp, 1, 1, fin))
            continue;
        v.push_back(tmp);
        c++;
    }
    unsigned int ss = v.size();
    for(int i = 0; i < 3; i++)
        v.push_back(0);
    fprintf(fout, "%.8x ", ss);
    for(unsigned long i = 0; i < v.size(); i += 4)
        fprintf(fout, "%.8x ", (v[i] << 24) | (v[i + 1] << 16) | (v[i + 2] << 8) | v[i + 3]);
    printf("%d bytes dumped\n", c);
    fclose(fin);
    fclose(fout);
    return 0;
}
