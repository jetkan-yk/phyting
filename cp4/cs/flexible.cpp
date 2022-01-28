#include <bits/stdc++.h>
using namespace std;

const int MAXN = 102;

int w, n, a[MAXN];

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> w >> n;
    a[0] = 0, a[n + 1] = w;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> ans;
    // Choose any 2 pairs of l, r
    for (int l = 0; l <= n + 1; l++)
        for (int r = l + 1; r <= n + 1; r++)
            ans.push_back(a[r] - a[l]);

    // Sort and remove duplicates
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (int x : ans)
        cout << x << " ";
    cout << endl;
}