#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define MAXM 10004

int m;
string line, name;
set<string> names;
unordered_map<string, int> word_count;
unordered_map<string, set<string>> word_to_names;
vector<string> msg[MAXM];
vector<pair<int, string>> common_words;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    // Read input and a whitespace for getline to work
    cin >> m >> ws;
    for (int i = 0; i < m; i++) {
        // Read the whole input line
        getline(cin, line);

        // Split whole line by whitespace, store into msg[i]
        size_t pos = 0, next_pos;
        while ((next_pos = line.find(" ", pos)) != string::npos) {
            msg[i].push_back(line.substr(pos, next_pos - pos));
            pos = next_pos + 1;
        }
        msg[i].push_back(line.substr(pos, next_pos - pos));
    }

    // For each line of input
    for (int i = 0; i < m; i++) {
        name = msg[i][0];
        // Keep track of a set of unique names
        names.insert(name);

        // For each word in the input
        for (auto it = msg[i].begin() + 1; it != msg[i].end(); it++) {
            string word = *it;

            // Map the word to a set of names
            word_to_names[word].insert(name);

            // Update the word's count
            if (word_count.find(word) == word_count.end())
                word_count[word] = 1;
            else
                word_count[word]++;
        }
    }

    // Find common words that are mentioned by every user
    for (auto it = word_to_names.begin(); it != word_to_names.end(); it++) {
        string word = it->fi;
        int num_mentioned = it->se.size();

        if (num_mentioned == names.size()) {
            // Negate first value for descending order
            // Alternatively, you can define your own comparator
            common_words.push_back(make_pair(-word_count[word], word));
        }
    }

    // Sort common words
    sort(common_words.begin(), common_words.end());

    // Output answer
    if (common_words.empty())
        cout << "ALL CLEAR\n";
    else
        for (auto x : common_words) cout << x.se << "\n";
}