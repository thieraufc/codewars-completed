#include <stdio.h>
#include <string.h>

unsigned bin_to_decimal(const char* bin){
    char *p = bin;
    int len = strlen(bin);
    p += len-1;
    int result = 0;

    for(int i = 0; i != len; ++i)
       result += ( (int) (*p-- - 48) ) << i;

    return result;
}

int main(void) {
    printf("%u\n", bin_to_decimal("1010"));
    printf("%u\n", bin_to_decimal("1111"));
    printf("%u\n", bin_to_decimal("1101"));
    printf("%u\n", bin_to_decimal("1000"));
    printf("%u\n", bin_to_decimal("0110"));
    return 0;
}
