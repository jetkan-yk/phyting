#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
unordered_set<int> invalid;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        // 0-indexed
        a--, b--;
        if (a > b) swap(a, b);
        int invMask = (1 << a) | (1 << b);
        invalid.insert(invMask);
    }

    // Try all possible combinations in bitmask representation
    int ways = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int can_work = 1;
        // Check if the current mask doesn't contain any invalid pair
        for (int invMask : invalid) {
            // Count number of 1-bits
            int num_bits = __builtin_popcount(mask & invMask);
            if (num_bits == 2) {
                can_work = 0;
                break;  // Early termination
            }
        }
        ways += can_work;
    }

    // Output answer
    cout << ways << endl;
}