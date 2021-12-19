#include <bits/stdc++.h>
using namespace std;

#define MAXN 20004

int n, m, dragon[MAXN], knight[MAXN];

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    while (cin >> n >> m) {
        // Terminate program when input is 0 0
        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; i++) cin >> dragon[i];
        for (int i = 0; i < m; i++) cin >> knight[i];

        // Sort both arrays
        sort(dragon, dragon + n);
        sort(knight, knight + m);

        // Assign each dragon to the smallest possible knight
        int k = 0, ans = 0;
        bool doomed = false;
        for (int d = 0; d < n && !doomed; d++) {
            // Finding a knight
            while (k < m && knight[k] < dragon[d]) k++;
            // Ran out of knight
            if (k == m) doomed = true;
            // Found a knight
            ans += knight[k++];
        }

        if (doomed)
            cout << "Loowater is doomed!\n";
        else
            cout << ans << "\n";
    }
}