#include <bits/stdc++.h>
using namespace std;

string s;
const int MAXS = 100005;
int n, bracket[MAXS], square[MAXS], question[MAXS];

int main() {
    cin >> s;
    n = s.size();

    // Open symbol is +1, close symbol is -1
    for (int i = 0; i < n; i++) {
        bracket[i] += (s[i] == '(');
        bracket[i] -= (s[i] == ')');
        square[i] += (s[i] == '[');
        square[i] -= (s[i] == ']');
        question[i] = (s[i] == '?');
    }

    // Prefix sum
    for (int i = 1; i < n; i++) {
        bracket[i] += bracket[i - 1];
        square[i] += square[i - 1];
        question[i] += question[i - 1];
    }

    int count = 0;
    // s1 = s[0, i), s2 = s[i, n)
    for (int i = 2; i < n; i += 2) {
        int needed1 = abs(bracket[i - 1]) + abs(square[i - 1]);
        int question1 = question[i - 1];

        int needed2 = abs(bracket[n - 1] - bracket[i - 1]) + abs(square[n - 1] - square[i - 1]);
        int question2 = question[n - 1] - question[i - 1];

        if ((question1 >= needed1 && (question1 - needed1) % 2 == 0) &&
            (question2 >= needed2 && (question2 - needed2) % 2 == 0))
            count += 1;
    }
    cout << count << endl;
}
