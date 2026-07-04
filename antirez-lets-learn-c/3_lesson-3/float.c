#include <stdio.h>

int main(void){
    int a = 10;
    float y = 1.234;

    printf("%d %f\n", a, y);
    printf("%d %.3f\n", a, y);
    printf("%x %.3f\n", a, y);
    printf("%X %.3f\n", a, y);
    return 0;
}