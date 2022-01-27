#include <bits/stdc++.h>
using namespace std;

int freq[7], roll[7], n, x;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        roll[x] = i;
        freq[x]++;
    }

    for (int i = 6; i > 0; i--) {
        if (freq[i] == 1) {
            printf("%d\n", roll[i]);
            return 0;
        }
    }

    printf("none\n");
}