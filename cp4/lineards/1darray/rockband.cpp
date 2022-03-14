/**
 * Check all rows form a permutation in O(1)
 * by checking whether # unique items == # column
 */
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int MAXN = 1e6 + 7;

int n, s, x;
vector<vi> a;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        a.push_back(vi());
        for (int j = 0; j < s; j++) {
            cin >> x;
            a[i].push_back(x);
        }
    }

    vector<bool> selected(s, false);
    vector<int> ans;
    for (int j = 0; j < s; j++) {
        // Insert all songs at column j
        for (int i = 0; i < n; i++) {
            int song = a[i][j];
            if (!selected[song]) {
                ans.push_back(song);
                selected[song] = true;
            }
        }

        // Check if all rows form a permutation
        if (ans.size() == (j + 1)) break;
    }

    // Output answer
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x << " ";
    cout << "\n";
}