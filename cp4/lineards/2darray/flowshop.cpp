/**
 * Greedy scheduling
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int n, m, work, ans, station[MAXN];

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        ans = 0;
        for (int j = 0; j < m; j++) {
            cin >> work;
            station[j] = ans = max(station[j], ans) + work;
        }
        cout << ans << " ";
    }
}