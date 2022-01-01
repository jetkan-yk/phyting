#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1003;
const int MAXM = 30;

set<int> s;
int a[MAXN], q[MAXM], ans[MAXM], n, m, tc;

int main() {
    // Read input
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        scanf("%d", &m);
        for (int i = 0; i < m; i++) scanf("%d", &q[i]);

        // Create all n^2 sums
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                s.insert(a[i] + a[j]);

        // Calculate answer
        for (int i = 0; i < m; i++) {
            auto lb = s.lower_bound(q[i]);
            int hi = *lb;
            int lo = lb == s.begin() ? *lb : *(--lb);

            ans[i] = abs(q[i] - lo) <= abs(q[i] - hi) ? lo : hi;
        }

        // Output answer
        printf("Case %d:\n", ++tc);
        for (int i = 0; i < m; i++) {
            printf("Closest sum to %d is %d.\n", q[i], ans[i]);
        }
    }
}