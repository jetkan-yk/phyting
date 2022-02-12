#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

int n, u, v, w;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    vector<ii> adjList[n];

    // cin >> u >> v >> w;  // 0, 1, 6
    // adjList[u].push_back(ii(v, w));

    int adjMat[n][n];
    memset(adjMat, -1, sizeof adjMat);

    cin >> u >> v >> w;  // 0, 1, 6
    adjMat[u][v] = w;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
}