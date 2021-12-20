#include <bits/stdc++.h>
using namespace std;

#define MAXN 2003
#define MAXW 100005
#define INF 2000000009

int C, n, value[MAXN], weight[MAXN], memo[MAXN][MAXW];

// i is current item, w is the bag's current weight
int bag(int i, int w) {
    // Considered all items or bag is full
    if (i == n || w == C) return 0;
    // Bag exceeded capacity limit
    if (w > C) return -INF;

    // Previously computed state
    if (memo[i][w] != -1) return memo[i][w];

    // Best value if we are taking item i
    int taking = bag(i + 1, w + weight[i]) + value[i];
    // Best value if we are not taking item i
    int not_taking = bag(i + 1, w);
    // Consider either taking or not taking item i
    return memo[i][w] = max(taking, not_taking);
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    while (cin >> C >> n) {
        // Read input
        for (int i = 0; i < n; i++)
            cin >> value[i] >> weight[i];

        // Reset memo
        memset(memo, -1, sizeof memo);
        vector<bool> pick(n, false);

        // Dynamic programming
        cout << bag(0, 0) << endl;

        // Output answer
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= C; j++)
                cout << memo[i][j] << " ";
            cout << endl;
        }
    }
}