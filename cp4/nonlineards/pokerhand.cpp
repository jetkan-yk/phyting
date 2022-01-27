/*
Kattis - pokerhand

Input:
AC AD AH AS KD

Output:
4
*/

#include <bits/stdc++.h>
using namespace std;

int ans;
string S[5];
// Declare variables here
unordered_map<char, int> freq;

int main() {
    // Read 5 strings into array S[]
    for (int i = 0; i < 5; i++) {
        cin >> S[i];
    }

    // For each hand in S[]:
    for (int i = 0; i < 5; i++) {
        // 1. Get the rank
        char rank = S[i][0];
        // 2. Increase the rank's count by 1
        freq[rank]++;
    }

    // For each rank's count:
    for (auto x : freq) {
        // 1. Update answer if count > current answer
        ans = max(ans, x.second);
    }

    // Output answer
    cout << ans;
}