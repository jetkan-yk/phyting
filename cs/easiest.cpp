#include <bits/stdc++.h>
using namespace std;

int n, target, ans;

// Find the sum of digit, O(# digits) i.e. O(logn)
int sum_digit(int x) {
    int result = 0;
    while (x) {
        result += x % 10;
        x /= 10;
    }
    return result;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    while (cin >> n) {
        // Terminate program when input is 0
        if (n == 0) break;

        target = sum_digit(n);

        ans = 10;
        // Keep trying new answer by increasing 1
        while (ans++) {
            if (sum_digit(n * ans) == target) {
                // Found correct answer
                cout << ans << "\n";
                break;
            }
        }
    }
}