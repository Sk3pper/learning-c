#include <stdio.h>

int sum(int a, int b){
    int c;

    c = a + b;

    return c;
}

int main(void){
    printf("The sum is %d", sum(10, 20));
    return 0;
}