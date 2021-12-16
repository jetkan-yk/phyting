#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int most_votes, winner_count;
string name, winner;
unordered_map<string, int> candidates;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input
    while (getline(cin, name)) {
        if (name == "***") break;

        // Create new candidate entry or increase candidate's count by 1
        if (candidates.find(name) == candidates.end())
            candidates[name] = 1;
        else
            candidates[name]++;
    }

    // Find most votes
    for (auto it = candidates.begin(); it != candidates.end(); it++)
        most_votes = max(most_votes, it->se);

    // Count candidates with most_votes, get winner's name
    for (auto it = candidates.begin(); it != candidates.end(); it++) {
        if (it->se == most_votes) {
            winner = it->fi;
            winner_count++;
        }
    }

    // Output answer
    if (winner_count > 1)
        cout << "Runoff!" << endl;
    else
        cout << winner << endl;
}