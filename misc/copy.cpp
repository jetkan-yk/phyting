#include <bits/stdc++.h>
using namespace std;

struct Box {
    int i, a[3];
};

int main() {
    Box box = {1, {2, 3, 4}};
    auto [i, a] = box;
    auto& [i2, a2] = box;

    i = 5;
    a[0] = 6;

    cout << box.i << endl;
    for (int idx = 0; idx < 3; idx++) {
        cout << box.a[idx] << " ";
    }
    cout << endl;

    i2 = 7;
    a2[0] = 8;

    cout << box.i << endl;
    for (int idx = 0; idx < 3; idx++) {
        cout << box.a[idx] << " ";
    }
    cout << endl;
}