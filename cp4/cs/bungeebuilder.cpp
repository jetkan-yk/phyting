/* Kattis - bungeebuilder

Input:
10
3 5 1 4 2 3 7 2 2 5

Output:
4
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000006

// Declare variables here
int N, height[MAXN];

// Sliding window from left to right, returns the max distance, O(N)
int sliding(int N, int height[]) {
    int i = 0, ans = 0, bottom = height[0];

    for (int j = 1; j < N; j++) {
        if (height[i] <= height[j]) {
            // Form a bridge between i and j, calculate the max distance
            ans = max(ans, height[i] - bottom);
            // Set j as the new i
            i = j;
            bottom = height[i];
        } else {
            // Keep searching for the lowest bottom
            bottom = min(bottom, height[j]);
        }
    }

    return ans;
}

int main() {
    // Read inputs
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }

    // Get forward result
    int ans_forward = sliding(N, height);
    // Reverse the height array in-place
    reverse(begin(height), begin(height) + N);
    // Get backward result
    int ans_backward = sliding(N, height);

    // Output the max of both forward & backward result
    cout << max(ans_forward, ans_backward);
}