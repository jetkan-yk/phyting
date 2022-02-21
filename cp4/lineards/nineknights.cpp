#include <bits/stdc++.h>
using namespace std;

char chess[12][12];
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int knight = 0;

int main() {
    for (int i = 2; i < 7; i++) {
        for (int j = 2; j < 7; j++) {
            cin >> chess[i][j];
            if (chess[i][j] == 'k') knight++;
        }
    }

    if (knight != 9) {
        cout << "invalid";
        return 0;
    }

    for (int i = 2; i < 7; i++) {
        for (int j = 2; j < 7; j++) {
            for (int k = 0; k < 8 && chess[i][j] == 'k'; k++) {
                if (chess[i + dy[k]][j + dx[k]] == 'k') {
                    cout << "invalid";
                    return 0;
                }
            }
        }
    }

    cout << "valid";

    return 0;
}