/** 
 * BSTA version, O(nlogb)
 **/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
int n, b, pop[MAXN];

// Check if can collect all votes with current average votes per box
bool can(int avg) {
    int box = b;
    bool possible = true;

    // Calculate number of box required for each city
    for (int i = 0; i < n && possible; i++) {
        box -= ceil(pop[i] / (double)avg);
        // Not enough box to collect all votes
        if (box < 0) possible = false;
    }

    return possible;
}

int main() {
    while (scanf("%d %d", &n, &b)) {
        if (n == -1 && b == -1) break;
        // Read input
        for (int i = 0; i < n; i++)
            scanf("%d", &pop[i]);

        // BSTA
        int lo = 1, hi = 5000000;
        // log_2(5000000) = 22.25, the maximum number of iterations is 23
        for (int i = 0; i < 23; i++) {
            int mid = (lo + hi) >> 1;  // Bit operation, i.e. (lo + hi) / 2, but faster
            can(mid) ? hi = mid : lo = mid;
        }
        // Output answer, after 23 iterations lo & hi would've converged to the answer
        printf("%d\n", hi);
    }
}