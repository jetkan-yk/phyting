#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

#define fi first
#define se second

string s;
stack<char> open;
vector<ii> match;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> s;

    // Mark all valid matching brackets
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            open.push(i);
        else if (s[i] == ')') {
            match.push_back(ii(open.top(), i));
            open.pop();
        }
    }

    // Try all valid bracket combinations using bitmask
    int n = match.size();
    vector<string> ans;
    for (int mask = 0; mask < (1 << n) - 1; mask++) {
        // Store all bracket indices that we want to include
        vector<int> b_id;
        // Check each bit of the mask
        for (int i = 0; i < n; i++) {
            // Include i-th bracket pair
            if (mask & (1 << i)) {
                b_id.push_back(match[i].fi);
                b_id.push_back(match[i].se);
            }
        }
        sort(b_id.begin(), b_id.end());

        // Generate expression
        string exp = "";
        for (int i = 0, j = 0; i < s.size(); i++) {
            if (s[i] != '(' && s[i] != ')')
                exp += s[i];
            else if (j < b_id.size() && i == b_id[j]) {
                exp += s[i];
                j++;
            }
        }
        ans.push_back(exp);
    }

    // Sort and remove duplicates
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    // Output answer
    for (string a : ans) cout << a << endl;
}