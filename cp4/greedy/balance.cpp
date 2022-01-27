/* UVa 410 - Station Balance

Input:
2 3
6 3 8
3 5
51 19 27 14 33
5 9
1 2 3 5 7 11 13 17 19

Output:
Set #1
 0: 6 3
 1: 8
IMBALANCE = 1.00000

Set #2
 0: 51
 1: 19 27
 2: 14 33
IMBALANCE = 6.00000

Set #3
 0: 1 17
 1: 2 13
 2: 3 11
 3: 5 7
 4: 19
IMBALANCE = 11.60000
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXS 10

// Declare variables here
int C, S, M[MAXS], TC = 1, s1, s2;
double imb, sum, avg;

int main() {
    while (cin >> C >> S) {
        sum = imb = 0;
        // Read input
        for (int i = 0; i < S; i++) {
            cin >> M[i];
            sum += M[i];
        }
        avg = sum / C;

        // Pad M with 0
        for (int i = S; i < 2 * C; i++) {
            M[i] = 0;
        }

        sort(M, M + 2 * C);

        // Output answer
        printf("Set #%d\n", TC++);
        for (int i = 0; i < C; i++) {
            printf(" %d:", i);
            s1 = M[i], s2 = M[2 * C - i - 1];
            // Don't print 0
            if (s1) printf(" %d", s1);
            if (s2) printf(" %d", s2);
            printf("\n");
            imb += abs(avg - (s1 + s2));
        }

        // 5 digits after decimal point
        printf("IMBALANCE = %.5f\n\n", imb);
    }
}