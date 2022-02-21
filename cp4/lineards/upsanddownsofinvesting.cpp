/**
 * Prefix sum method to count peaks and valleys
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1004;

int n, u, d, price[MAXN], up[MAXN], down[MAXN];

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> n >> u >> d;
    for (int i = 0; i < n; i++)
        cin >> price[i];

    // Count consecutive up & down trends
    up[0] = down[0] = 1;
    for (int i = 1; i < n; i++) {
        up[i] = (price[i - 1] < price[i]) ? up[i - 1] + 1 : 1;
        down[i] = (price[i - 1] > price[i]) ? down[i - 1] + 1 : 1;
    }

    // Count peaks
    int peak = 0;
    for (int i = 0; i + u - 1 < n; i++)
        if (up[i] >= u && up[i + 1] == 1 && down[i + u - 1] == u)
            peak++;

    // Count valleys
    int valley = 0;
    for (int i = 0; i + d - 1 < n; i++)
        if (down[i] >= d && down[i + 1] == 1 && up[i + d - 1] == d)
            valley++;

    cout << peak << " " << valley << "\n";
}