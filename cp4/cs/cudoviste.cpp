#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;

const char car = 'X';
const char building = '#';
const char space = '.';

int r, c, freq[5];
char a[MAXN][MAXN];

int main() {
    // Read input
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf(" %c", &a[i][j]);

    for (int i = 0; i < r - 1; i++)
        for (int j = 0; j < c - 1; j++) {
            // Count number of cars and buildings
            int kCar = 0, kBuilding = 0;

            // Check 2x2 slots
            for (int di = 0; di < 2; di++)
                for (int dj = 0; dj < 2; dj++) {
                    kCar += (a[i + di][j + dj] == car);
                    kBuilding += (a[i + di][j + dj] == building);
                }

            // Store counts
            if (kBuilding > 0) continue;
            freq[kCar]++;
        }

    // Output answer
    for (int x : freq) cout << x << "\n";
}