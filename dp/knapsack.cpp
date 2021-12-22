#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAXN = 2003;

int C, n, value[MAXN], weight[MAXN];

// Find the best value after considering item i with w allowed weight
int top_down(int i, int w, vvi& memo) {
    // state is a reference variable, any changes to it will be reflected on memo
    int& state = memo[i][w];

    // Base case: 0 item or no remaining weight
    if (i == 0 || w == 0) return state = 0;

    // Previously computed state
    if (state != -1) return state;

    // If item is heavier than the bag's allowed weight, don't take it
    if (w < weight[i]) return state = top_down(i - 1, w, memo);
    // Otherwise consider either taking or not taking the item
    return state = max(top_down(i - 1, w - weight[i], memo) + value[i],
                       top_down(i - 1, w, memo));
}

// Backtrack the memo to trace which items are selected
void trace(int i, int w, const vvi& memo, vi& bag) {
    // Traced all items, job done
    if (i == 0) return;

    if (memo[i][w] == memo[i - 1][w]) {
        // Not taking item i
        return trace(i - 1, w, memo, bag);
    } else {
        // Taking item i
        bag.push_back(i);
        return trace(i - 1, w - weight[i], memo, bag);
    }
}

int main() {
    while (cin >> C >> n) {
        // Fast I/O
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);

        // Read input
        for (int i = 1; i <= n; i++)  // Using 1-indexed
            cin >> value[i] >> weight[i];

        // Reset memo
        vvi memo = vector<vi>(n + 1, vi(C + 1, -1));
        vi bag;

        // Dynamic programming
        top_down(n, C, memo);
        trace(n, C, memo, bag);

        // Output answer
        cout << bag.size() << "\n";
        for (int x : bag) cout << x - 1 << " ";  // Revert to 0-indexed
        cout << "\n";
    }
}