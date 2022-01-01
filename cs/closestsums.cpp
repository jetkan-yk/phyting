#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1003;

int a[MAXN], n, m, target, ans, sum, tc;

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        scanf("%d", &m);

        printf("Case %d:\n", ++tc);
        while (m--) {
            scanf("%d", &target);

            // Initialize answer as sum of first 2 numbers
            ans = a[0] + a[1];
            // Find closest sum, O(n^2)
            for (int i = 0; i < n; i++)
                for (int j = i + 1; j < n; j++) {
                    sum = a[i] + a[j];
                    // Found a closer sum
                    if (abs(sum - target) < abs(ans - target))
                        ans = sum;
                }

            printf("Closest sum to %d is %d.\n", target, ans);
        }
    }
}