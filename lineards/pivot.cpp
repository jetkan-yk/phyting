#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int N, a[MAXN], max_left[MAXN], min_right[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read input
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> a[i];

    // min_left[i] is the minimum value from everything to the left of a[i]
    max_left[0] = a[0];
    for (int i = 1; i < N; i++)
        max_left[i] = max(max_left[i - 1], a[i]);

    // max_right[i] is the maximum value from everything to the left of a[i]
    min_right[N - 1] = a[N - 1];
    for (int i = N - 2; i >= 0; i--)
        min_right[i] = min(min_right[i + 1], a[i]);

    int ans = 0;
    for (int i = 0; i < N; i++)
        // Count number of max_left[i] == min_right[i]
        ans += (max_left[i] == min_right[i]);

    // Output answer
    cout << ans;
}