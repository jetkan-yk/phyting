#include <bits/stdc++.h>
using namespace std;

int main() {
    int i = 5;
    int* ip = &i;

    char c = 'a';
    char* cp = &c;

    cout << &i << " " << ++ip << endl;
    cout << (void*) &c << " " << (void*) ++cp << endl;

    char s[10] = "abc";
}