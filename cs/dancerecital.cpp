#include <bits/stdc++.h>
using namespace std;

const int MAXN = 11;
const int MAXS = 26;

int n, id[MAXN], repeat[MAXN][MAXN];
string s[MAXN];

int count_repeat(const string& s1, const string& s2) {
    int i = 0, j = 0, repeat = 0;

    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j])
            i++, j++, repeat++;
        else if (s1[i] < s2[j])
            i++;
        else
            j++;
    }

    return repeat;
}

int main() {
    // Read input
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];

    // Pre-calcuate # of quick change between every pair of rountines
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            repeat[i][j] = repeat[j][i] = count_repeat(s[i], s[j]);

    // Try all possible permutations
    int ans = MAXN * MAXS;
    for (int i = 0; i < n; i++) id[i] = i;
    // Permute using index number
    do {
        int cur = 0;
        for (int i = 0; i < n - 1; i++)
            cur += repeat[id[i]][id[i + 1]];
        ans = min(ans, cur);
    } while (next_permutation(id, id + n));

    cout << ans << endl;
}