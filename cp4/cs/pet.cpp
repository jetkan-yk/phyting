#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int winner, max_score = -INF, score, x;

int main() {
    for (int i = 1; i <= 5; i++) {
        score = 0;
        for (int j = 0; j < 4; j++) {
            scanf("%d", &x);
            score += x;
        }
        if (score > max_score) {
            max_score = score;
            winner = i;
        }
    }
    printf("%d %d\n", winner, max_score);
}