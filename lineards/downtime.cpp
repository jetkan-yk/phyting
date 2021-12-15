#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n, k, request, ans, t[MAXN];
queue<int> process;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read input
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        // Add time for request to finish processed
        process.push(t[i] + 1000);
        // Add request count by 1
        request++;

        // Remove all processed requests before t[i]
        while (!process.empty() && process.front() <= t[i]) {
            process.pop();
            request--;
        }

        // Update answer
        ans = max(ans, request);
    }

    // Note the float conversion for ceil to work
    cout << ceil((float)ans / k) << "\n";
}