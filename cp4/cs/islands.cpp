#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000;

int n, k, a[12];

bool isIsland(int l, int r) {
    int outer = max(a[l - 1], a[r + 1]);
    for (int i = l; i <= r; i++)
        if (a[i] <= outer)
            return false;
    return true;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < 12; j++)
            cin >> a[j];

        int count = 0;
        // Choose any 2 pairs of l, r
        for (int l = 1; l < 11; l++)
            for (int r = l; r < 11; r++)
                count += isIsland(l, r);

        cout << k << " " << count << endl;
    }
}