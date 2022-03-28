#include <stdio.h>

int main() {
    int a = 1045;
    int* p;
    p = &a;
    printf("Size of integer is %d bytes\n", sizeof(int));
    printf("Address = %d, value = %d\n", p, *p);
    printf("Address = %d, value = %d\n", p + 1, *(p + 1));

    char *p0;
    p0 = (char*) p;
    printf("Size of char is %d bytes\n", sizeof(char));
    printf("Address = %d, value = %d\n", p0 + 1, *(p0 + 1));

    // Void pointer - generic data type, cannot be dereferenced
    void *p1;
    p1 = p0;
    printf("Address = %d, address + 1 = %d\n", p1, p1 + 1);
}