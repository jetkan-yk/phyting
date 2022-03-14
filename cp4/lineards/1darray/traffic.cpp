/**
 * Prefix sum method to generate delta values
 * Be careful of max array size
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXT = 3e6 + 7;

int n, dist[2][MAXT], delta[2][MAXT], x;
vector<int> t[2];

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> dist[0][0] >> dist[1][0];
    for (int i = 0; i < 2; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> x;
            t[i].push_back(x);
        }
    }

    // Pre-calculate delta values
    for (int i = 0; i < 2; i++) {
        bool start = true;
        // Mark start & stop points
        for (int j : t[i]) {
            if (start)
                delta[i][j + 1] = 1;
            else
                delta[i][j + 1] = -1;
            start = !start;  // Alternate start & stop
        }
        // Apply prefix sum to delta
        for (int j = 1; j < MAXT; j++)
            delta[i][j] += delta[i][j - 1];
    }

    // Apply delta values to distance
    for (int i = 0; i < 2; i++)
        for (int j = 1; j < MAXT; j++)
            dist[i][j] = dist[i][j - 1] + delta[i][j];

    // Output answer
    for (int j = 0; j < MAXT; j++)
        if (abs(dist[0][j] - dist[1][j]) < 5) {
            cout << "bumper tap at time " + to_string(j) + "\n";
            return 0;
        }

    cout << "safe and sound\n";
}