#include <stdio.h>

int main(){

    int y=3;
    int z = (--y) + (y=10);
    printf("%d\n", z);
    
    return 0;
}