/**
 * Complete search to pre-calculate all answer, 
 * O(nb) where b = 380 is number of losing states
 **/
#include <bits/stdc++.h>
using namespace std;

const int N = 1000000000;

bool prime[N + 1];
vector<int> lose;

// Can only take (p - 1) stones
bool can_take(int i) {
    return prime[i + 1];
}

// Sieve of Eratosthenes
void sieve(int N) {
    for (int p = 2; p * p <= N; p++)
        if (prime[p])
            // Update all multiples of p
            for (int i = p * 2; i <= N; i += p)
                prime[i] = false;
}

int main() {
    memset(prime, true, sizeof prime);
    sieve(N);

    // Base case: when you have 0 stone, you lose
    lose.push_back(0);
    // For each number i
    for (int i = 1; i <= N; i++) {
        bool win = false;
        for (auto l = lose.begin(); l != lose.end() && !win; l++)
            // If there is a way to take stones such that
            // you leave a losing state to your opponent, you win
            if (can_take(i - *l)) win = true;
        if (!win) lose.push_back(i);
    }

    // Output all losing states
    for (int x : lose) cout << x << ", ";
    cout << endl
         << lose.size() << endl;
}