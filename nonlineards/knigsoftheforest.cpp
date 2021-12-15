#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int k, n, y, p, karl, winner, power[MAXN];
priority_queue<int> pool;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> k >> n;
    for (int i = 0; i <= n + k - 2; i++) {
        cin >> y >> p;
        // Store Karl's power
        if (i == 0) karl = p;
        // If year is 2011, it is an initial moose
        if (y == 2011) pool.push(p);
        // Otherwise, it is a replacement moose
        else power[y - 2011] = p;
    }

    // Simulate from index 0 to index n - 1
    for (int i = 0; i < n; i++) {
        winner = pool.top();
        // Karl wins, early terminate
        if (winner == karl) {
            cout << i + 2011 << "\n";
            return 0;
        } else {
            // Remove winner
            pool.pop();
            // Insert next year's replacement
            pool.push(power[i + 1]);
        }
    }
    // Karl never wins, output unknown
    cout << "unknown\n";
}