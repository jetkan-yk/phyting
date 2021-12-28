/* UVa 12032 - The Monkey and the Oiled Bamboo

Input:
2
5
1 6 7 11 13
4
3 9 10 14

Output:
Case 1: 5
Case 2: 6
*/

#include <bits/stdc++.h>
using namespace std;

// Bad practice in software engineering, but ok for CP
#define MAXN 100005
#define MAXR 10000007

// Declare variables here
int T, N, R[MAXN], ans;

// Returns true if can reach the top rung with k
bool can_reach(int k, int R[]) {
    for (int i = 0; i < N; i++) {
        int gap = (i == 0) ? R[0] : R[i] - R[i - 1];

        if (gap > k) {
            return false;
        } else if (gap == k) {
            k--;
        }
    }
    return true;
}

int main() {
    // Read T
    cin >> T;
    // For each case i
    for (int i = 0; i < T; i++) {
        // Read input
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> R[j];
        }

        // Initialize binary search low & high
        int lo = 1, hi = MAXR;
        // Binary search terminating condition
        while (lo <= hi) {
            // Pick the middle as k
            int mid = hi - (hi - lo) / 2;  // Prevent integer overflow

            if (can_reach(mid, R)) {
                // Keep the answer
                ans = mid;
                // Look for smaller k
                hi = mid - 1;
            } else {
                // Look for bigger k
                lo = mid + 1;
            }
        }

        // Output answer
        printf("Case %d: %d\n", i + 1, ans);
    }
}