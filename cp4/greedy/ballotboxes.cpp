/** 
 * Greedy version using Priority Queue, O(blogn)
 **/
#include <bits/stdc++.h>
using namespace std;

// City = [average votes per box, population size, number of boxes]
typedef tuple<double, int, int> City;

int N, B, total;

int main() {
    while (cin >> N >> B) {
        if (N == -1 && B == -1) break;

        priority_queue<City> pq;

        for (int i = 0; i < N; i++) {
            cin >> total;
            pq.push(City{total / 1.0, total, 1});
        }

        B -= N;
        while (B--) {
            auto [votes, total, box] = pq.top();
            pq.pop();
            pq.push(City{total / (box + 1.0), total, box + 1});
        }

        cout << ceil(get<0>(pq.top())) << endl;
    }
}