#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int tc, n, x;
unordered_map<int, unordered_set<int>> option;
unordered_map<int, int> available;

void debug() {
    for (auto a : available)
        cout << a.fi << " " << a.se << endl;

    for (auto o : option) {
        cout << o.fi << ": ";
        for (auto i : o.se)
            cout << i << " ";
        cout << endl;
    }
}

bool asgn(int i) {
    if (i == 0) return true;

    for (int x : option[i]) {
        if (available[x] == 0) continue;

        available[x]--;
        if (asgn(i - 1)) return true;
        available[x]++;
    }
    return false;
}

int main() {
    cin >> tc;

    while (tc--) {
        available.clear();
        option.clear();

        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;

            if (available.find(x) == available.end())
                available[x] = 1;
            else
                available[x]++;

            int half = x;
            while (half > 0) {
                if (option.find(half) == option.end())
                    option[half] = unordered_set<int>{x};
                else
                    option[half].insert(x);
                half /= 2;
            }
        }

        // debug();

        if (asgn(n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}