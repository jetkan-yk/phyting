#include <bits/stdc++.h>
using namespace std;

int n;
string x;

bool isValid(const string& date) {
    return true;
}

int getDay(const string& date) {
    return 0;
}

string printDate(const string& date) {
    string ret = "";
    for (int i = 0; i < 8; i++) {
        if (i == 2 || i == 4) ret += " ";
        ret += date[i];
    }
    return ret;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < 3; j++) {
            cin >> x;
            s += x;
        }

        // Try all permutations
        int best_day = 1e9, cur_day;
        string best_date = "";
        do {
            if (isValid(s)) {
                cur_day = getDay(s);
                if (best_day > cur_day) {
                    best_day = cur_day;
                    best_date = s;
                }
            }
        } while (next_permutation(s.begin(), s.end()));

        if (best_date != "")
            cout << to_string(best_day) + " " + printDate(best_date) << endl;
        else
            cout << 0 << endl;
    }
}