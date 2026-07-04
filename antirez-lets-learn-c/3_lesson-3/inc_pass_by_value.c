#include <stdio.h>

int incr(int x){
    x = x + 1;
    return x;
}

int main(void){
    int a = 10;
    incr(a); // v1
    // a = incr(a); // v2
    // a = incr(a); // v2
    // a = incr(a); // v2
    // a = incr(a); // v2
    printf("%d\n", a);
    return 0;
}