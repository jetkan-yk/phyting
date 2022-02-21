/**
 * Count inversion with O(n)
 * Find i < j where a[i] > a[j]
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int tc, n, a[MAXN];

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> tc;
    while (tc--) {
        // Read input
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        // Find i such that exist j where i < j and a[i] > a[j]
        vector<int> ans;
        int min_a = a[n];
        for (int i = n - 1; i > 0; i--) {
            if (a[i] > min_a)
                ans.push_back(a[i]);
            min_a = min(min_a, a[i]);
        }

        // Output answer
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (int x : ans)
            cout << x << "\n";
    }
}