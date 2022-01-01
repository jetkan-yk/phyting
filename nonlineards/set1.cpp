#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

string card[12];
vector<vi> ans;

// Maps symbol to either 0, 1 or 2
unordered_map<char, int> m {
    {'1', 0}, {'2', 1}, {'3', 2}, 
    {'D', 0}, {'S', 1}, {'O', 2}, 
    {'T', 0}, 
    {'R', 0}, {'G', 1}, {'P', 2}
};

bool can(const vi& ijk) {
    // Using bitmasks to store states of each categories
    int mask[] = {0, 0, 0, 0};

    // Mark symbols appeared in the cards
    for (auto i : ijk)
        for (int j = 0; j < 4; j++)
            mask[j] |= (1 << m[card[i][j]]);

    // Check each categories
    for (int i = 0; i < 4; i++) {
        int bits_on = __builtin_popcount(mask[i]);
        // We want just 1 or all 3 types of symbols to appear
        if (!(bits_on == 1 || bits_on == 3))
            return false;
    }
    return true;
}

int main() {
    // Read input
    for (int i = 0; i < 12; i++) cin >> card[i];

    // All 3-combinations
    for (int i = 0; i < 12; i++)
        for (int j = i + 1; j < 12; j++)
            for (int k = j + 1; k < 12; k++)
                if (can(vi{i, j, k}))
                    ans.push_back(vi{i, j, k});

    // Output answer
    if (!ans.empty())
        for (vi v : ans) {
            for (int x : v) cout << x + 1 << " ";
            cout << endl;
        }
    else
        cout << "no sets\n";
}