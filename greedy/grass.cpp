#include <bits/stdc++.h>
using namespace std;

#define EPS 0.000000009

// A sprinkler has a leftmost & rightmost fully covered points
struct sp {
    double l, r;
};

bool cmp(sp a, sp b) {
    return fabs(a.l - b.l) > EPS ? a.l < b.l : a.r > b.r;
}

int n, length, width, center, radius;
vector<sp> sprinklers;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    while (cin >> n >> length >> width) {
        // Read input
        for (int i = 0; i < n; i++) {
            cin >> center >> radius;

            // Discard sprinklers that cannot fully cover the width
            if (2 * radius < width) continue;

            // Find the inner square of the circle using Pythagoras Theorem
            double dx = sqrt(pow(radius, 2) - pow((width / 2.0), 2));
            // Leftmost & rightmost fully covered points of a sprinkler
            sprinklers.push_back(sp{center - dx, center + dx});
        }

        // Sort sprinklers with ascending l, then descending r
        sort(sprinklers.begin(), sprinklers.end(), cmp);

        // Area covered (from left) so far
        double covered = 0.0;
        int ans = 0;
        bool possible = true;
        // Checking each sprinkler
        for (auto i = sprinklers.begin(); i != sprinklers.end() && possible; i++) {
            // Covered the whole grass strip
            if (covered >= length) break;
            // Discard sprinkler if its completely inside the covered area
            else if (i->r < covered)
                continue;
            // There is a gap that is impossible to cover with any sprinkler
            else if (i->l > covered)
                possible = false;
            // Choose sprinkler that overlaps the "covered" point and has the largest coverage
            else {
                double max_right = i->r;
                auto max_j = i;
                // Check all sprinkler that overlaps the "covered" point
                for (auto j = i; j != sprinklers.end() && j->l <= covered; j++)
                    // Found a sprinkler that has larger coverage
                    if (j->r > max_right) {
                        max_right = j->r;
                        // Keep the max coverage sprinkler's iterator (id)
                        max_j = j;
                    }
                covered = max_right;
                i = max_j;
                ans++;
            }
        }

        // Output answer
        if (!possible || covered < length)
            cout << "-1\n";
        else
            cout << ans << "\n";

        // Clear container
        sprinklers.clear();
    }
}