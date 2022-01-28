#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, a[MAXN];

// Enforces non-circular left shift
int fixBits(int x) {
    return x & ((1 << 8) - 1);
}

// Applies scrambling to an integer
int scramble(int x) {
    return x ^ fixBits(x << 1);
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        // Try every possible answer
        for (int x = 0; x <= 255; x++) {
            if (scramble(x) == a[i]) {
                cout << x << " ";
                break;
            }
        }
    }
}