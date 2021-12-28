/**
 * Pre-computes prevH -> (token, curH) using "msg" as the transaction string
 * Note: all hash values have no trailing zeroes
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll H(ll previousHash, string& transaction, ll token) {
    ll v = previousHash;
    for (int i = 0; i < transaction.length(); i++) {
        v = (v * 31 + transaction[i]) % 1000000007;
    }
    return (v * 7 + token) % 1000000007;
}

const ll maxToken = 1e9 - 1;
const ll trailZ = 1e7;

string msg = "a";

int main() {
    for (int prevH = 1; prevH <= 100; prevH++)
        for (ll token = 0; token < maxToken; token++) {
            ll curH = H(prevH * trailZ, msg, token);
            if (curH % (trailZ * 10) == 0) {
                printf("m[%d] = pll(%lld, %lld);\n", prevH, token, curH / trailZ);
                break;
            }
        }
}