/* UVa 11450 - Wedding Shopping

Input:
3
100 4
3 8 6 4
2 5 10
4 1 3 3 7
4 50 14 23 8
20 3
3 4 6 8
2 5 10
4 1 3 5 5
5 3
3 6 4 8
2 10 6
4 7 3 1 7

Output:
75
19
no solution
*/

#include <bits/stdc++.h>
using namespace std;

#define INF 1000000009
#define MAXC 20
#define MAXK 20
#define MAXM 200

int N, M, C, K, price[MAXC][MAXK], memo[MAXK][MAXM];

// g is garment type, b is current budget
int buy(int g, int b) {
    if (b < 0) return -INF;
    if (g == C) return M - b;
    if (memo[g][b] != -1) return memo[g][b];

    // Try each model k for garment g
    int ans = -1;
    for (int k = 1; k <= price[g][0]; k++)
        ans = max(ans, buy(g + 1, b - price[g][k]));
    return memo[g][b] = ans;
}

int main() {
    scanf("%d", &N);
    while (N--) {
        // Read input
        scanf("%d %d", &M, &C);
        for (int i = 0; i < C; i++) {
            // price[i][0] is number of models for garment i
            scanf("%d", &price[i][0]);
            for (int j = 1; j <= price[i][0]; j++)
                // price[i][j] is the price of model j for garment i
                scanf("%d", &price[i][j]);
        }

        // Clear memory
        memset(memo, -1, sizeof memo);

        int ans = buy(0, M);

        // Output answer
        if (ans >= 0)
            printf("%d\n", ans);
        else
            printf("no solution\n");
    }
}