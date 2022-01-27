#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> s;

    int si = stoi(s), ans = 1e9;
    bool has_larger = false;
    // Try all digit permutations
    do {
        int pi = stoi(s);
        if (pi > si) {
            has_larger = true;
            ans = min(ans, pi);
        }
    } while (next_permutation(s.begin(), s.end()));

    // Output answer
    if (has_larger)
        cout << ans << endl;
    else
        cout << 0 << endl;
}