/**
 * Simple column-major iterate 2D array
 */
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    // Count moves
    int moves = 1;
    for (int j = 0; j < m; j++) {
        bool valid = true;
        for (int i = 0; i < n && valid; i++)
            if (a[i][j] != '_') valid = false;
        if (valid) moves++;
    }

    cout << moves << "\n";
}