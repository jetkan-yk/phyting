#include <bits/stdc++.h>
using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    int n, sum = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int max_sum = 2 * sum + 1;

    int dp[n + 1][max_sum];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < max_sum; j++)
            dp[i][j] = INT_MIN;

    dp[0][sum] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < max_sum; j++) {
            // Putting ith element in g0
            if (0 <= (j - a[i - 1]) && dp[i - 1][j - a[i - 1]] != INT_MIN)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1]] + a[i - 1]);

            // Putting ith element in g1
            if ((j + a[i - 1]) < max_sum && dp[i - 1][j + a[i - 1]] != INT_MIN)
                dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i - 1]]);

            // Ignoring ith element
            if (dp[i - 1][j] != INT_MIN)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }

    cout << dp[n][sum] << endl;
    return 0;
}
