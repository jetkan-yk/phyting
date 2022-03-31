#include <stdio.h>

void Increment(int a) {
    a = a + 1;
}

int main() {
    int a = 10;
    Increment(a);
    printf("%d\n", a);
}