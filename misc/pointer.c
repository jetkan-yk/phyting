#include <stdio.h>

int main() {
    int a = 10;
    int* p;
    p = &a;

    printf("Address of p is %d\n", p);
    printf("Size of integer is %d bytes\n", sizeof(int));
    printf("Address of p is %d\n", p + 2);
    printf("Content of p + 2 is %d\n", *(p + 2));
}