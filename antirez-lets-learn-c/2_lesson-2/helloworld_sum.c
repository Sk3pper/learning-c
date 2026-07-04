#include <stdio.h>

int sum(int a, int b){
    return a+b;
}

int main(void){
    // printf("Hello World Sk3pper! %d", sum(10, 20)); // [v1]
    printf("Hello World Sk3pper! %d %d", sum(10, 20), 50); // [v2]
    // printf("Hello World Sk3pper! %d %d", sum(10, 20)); // [v3]
    return 0;
}