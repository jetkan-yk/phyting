#include <bits/stdc++.h>
using namespace std;

int n, m, ans, x;
unordered_set<int> jack;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    while (cin >> n >> m) {
        // Keep looping until input is 0 0
        if (n == 0 && m == 0) break;

        // Reset counters
        ans = 0;
        jack.clear();

        // Read input
        while (n--) {
            cin >> x;
            jack.insert(x);
        }
        while (m--) {
            cin >> x;
            if (jack.find(x) != jack.end()) ans++;
        }

        // Output answer
        cout << ans << "\n";
    }
}