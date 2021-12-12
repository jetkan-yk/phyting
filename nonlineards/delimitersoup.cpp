#include <bits/stdc++.h>
using namespace std;

int L;
string str;
stack<char> expect;
unordered_map<char, char> match = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

int main() {
    // Read input, cin >> ws to consume endline token for getline to work
    cin >> L >> ws;
    getline(cin, str);

    for (int i = 0; i < L; i++) {
        char c = str[i];
        // Ignore whitespace
        if (isspace(c)) continue;

        auto delim = match.find(c);
        if (delim != match.end()) {
            // c is open delimiter
            expect.push(delim->second);  // Store the expected close delimiter in a stack
        } else {
            // c is close delimiter
            if (!expect.empty() && c == expect.top())
                expect.pop();
            else {
                // c is not the expected close delimiter
                cout << c << " " << i;
                // Terminate program early
                return 0;
            }
        }
    }
    cout << "ok so far";
}