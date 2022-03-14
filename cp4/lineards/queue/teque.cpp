#include <bits/stdc++.h>
using namespace std;

int N, x;
string op;
deque<int> d1, d2;
vector<int> ans;

int main() {
    // For fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> op >> x;

        // O(1) time for every operation type
        if (op == "get")
            ans.push_back(x < d1.size() ? d1[x] : d2[x - d1.size()]);
        else if (op == "push_back")
            d2.push_back(x);
        else if (op == "push_front")
            d1.push_front(x);
        else if (op == "push_middle")
            // Insert at the front of d2
            d2.push_front(x);

        // Rebalance d1 and d2
        // d1 is always the same size or 1 item more than d2
        if (d1.size() < d2.size()) {
            d1.push_back(d2.front());
            d2.pop_front();
        } else if (d1.size() > d2.size() + 1) {
            d2.push_front(d1.back());
            d1.pop_back();
        }
    }

    // Output all answer at one go for speed
    for (int x : ans)
        cout << x << "\n";
}