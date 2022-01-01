#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

#define fi first
#define se second

char c;
int scatter;
unordered_map<char, ii> expected;

int main() {
    // Create a mapping of char to its expected location
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            expected[char((4 * i + j) + 65)] = ii(i, j);

    // Read input
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            cin >> c;
            if (c == '.' || expected[c] == ii(i, j)) continue;
            scatter += abs(expected[c].fi - i) + abs(expected[c].se - j);
        }

    // Output answer
    cout << scatter << endl;
}