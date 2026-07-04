#include <stdio.h>

void incr(void){
    static int x = 0;
    x = x + 1;
    printf("%d\n", x); 
}

int main(void){
    incr();
    incr();
    incr();
    incr();
    return 0;
}