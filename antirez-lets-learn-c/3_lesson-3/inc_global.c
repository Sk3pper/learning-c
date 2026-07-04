#include <stdio.h>

int x = 0;

void incr(void){
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