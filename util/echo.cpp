#include "lib.hpp"

int main()
{
    char out1[] = "Enter a string and press [ENTER]: ";
    char out2[] = "You have entered: ";
    char in1[4096];
    prints(out1);
    scans(in1);
    prints(out2);
    prints(in1);
    return 0;
}
