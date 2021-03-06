#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAXN = 2003;

int C, n, value[MAXN], weight[MAXN];
vvi memo;

// Find the best value after considering item i with w allowed weight
int top_down(int i, int w) {
    // Previously computed state
    if (memo[i][w] != -1) return memo[i][w];

    // Base case: 0 item or no remaining weight
    if (i == 0 || w == 0) return memo[i][w] = 0;

    // If item is heavier than the bag's allowed weight, don't take it
    if (w < weight[i]) return memo[i][w] = top_down(i - 1, w);
    // Otherwise consider either taking or not taking the item
    return memo[i][w] = max(top_down(i - 1, w - weight[i]) + value[i],
                            top_down(i - 1, w));
}

// Fill the memo table using the bottom-up fashion
void bottom_up() {
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= C; w++) {
            if (i == 0 || w == 0)
                memo[i][w] = 0;
            else if (w < weight[i])
                memo[i][w] = memo[i - 1][w];
            else
                memo[i][w] = max(memo[i - 1][w - weight[i]] + value[i],
                                 memo[i - 1][w]);
        }
    }
}

// Backtrack the memo to trace which items are selected
void trace(int i, int w, vi& bag) {
    // Traced all items, job done
    if (i == 0) return;

    if (memo[i][w] == memo[i - 1][w]) {
        // Not taking item i
        return trace(i - 1, w, bag);
    } else {
        // Taking item i
        bag.push_back(i);
        return trace(i - 1, w - weight[i], bag);
    }
}

int main() {
    while (cin >> C >> n) {
        // Fast I/O
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);

        // Read input
        for (int i = 1; i <= n; i++)  // Change to 1-indexed
            cin >> value[i] >> weight[i];

        // Reset memo
        memo = vector<vi>(n + 1, vi(C + 1, -1));
        vi bag;

        // Dynamic programming
        // You may experiment by commenting away either 1 of the following 2 lines
        top_down(n, C);
        // bottom_up();
        trace(n, C, bag);

        // Output answer
        cout << bag.size() << "\n";
        for (int x : bag) cout << x - 1 << " ";  // Revert to 0-indexed
        cout << "\n";
    }
}