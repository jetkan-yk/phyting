#include <bits/stdc++.h>
using namespace std;

// Using 'll' as the shorthand of 'long long'
typedef long long ll;

// Note that we need to use long long instead of integers due to constraints (10^12)
ll n, sqrt_n;
// Using set because it automatically sorts items and removes duplicates
set<ll> ans;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> n;

    sqrt_n = sqrt(n);
    // Find divisors from 1 to square root of n
    for (ll i = 1; i <= sqrt_n; i++) {
        // If n mod i = 0, i.e. n is divisible by i
        if (n % i == 0) {
            // Problem requires (divisors - 1)
            ans.insert(i - 1);
            ans.insert((n / i) - 1);
        }
    }

    // Output answer
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << *it << " ";
    cout << "\n";
}