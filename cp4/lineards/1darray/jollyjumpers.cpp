#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define mp make_pair
#define fi first
#define se second

const int MAXN = 3000;
const int MAXX = 300000;

int n, a[MAXN], diff[MAXX];

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    while (cin >> n) {
        for (int i = 0; i < n; i++)
            cin >> a[i];

        memset(diff, 0, sizeof diff);
        for (int i = 1; i < n; i++)
            diff[abs(a[i] - a[i - 1])] = 1;

        bool isJolly = true;
        for (int i = 1; i < n; i++)
            if (!diff[i]) isJolly = false;
        if (isJolly)
            cout << "Jolly\n";
        else
            cout << "Not Jolly\n";
    }
}