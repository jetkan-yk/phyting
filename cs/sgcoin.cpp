/**
 * We can solve this problem by fixing the message to something short
 * (e.g. "a"), then pre-compute all possible prevHash -> (token, curHash) values.
 * 
 * Since the max value of a hash is 1e9 and knowing that every hash has 7 trailing zeroes,
 * there is only 100 distinct hashes. We just have to pre-compute 100 mappings and solve
 * the problem in O(1) time.
 **/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long, long> pll;

pll m[101];

const ll maxToken = 1e9 - 1;
const ll trailZ = 1e7;

string msg = "a";
ll prevH;

int main() {
    // Pre-computed value from sgcoin2.cpp
    m[1] = pll(29999335, 20);
    m[2] = pll(59999349, 40);
    m[3] = pll(89999363, 60);
    m[4] = pll(19999377, 70);
    m[5] = pll(49999391, 90);
    m[6] = pll(79999412, 10);
    m[7] = pll(9999426, 20);
    m[8] = pll(39999440, 40);
    m[9] = pll(69999454, 60);
    m[10] = pll(99999468, 80);
    m[11] = pll(29999482, 90);
    m[12] = pll(59999503, 10);
    m[13] = pll(89999517, 30);
    m[14] = pll(19999531, 40);
    m[15] = pll(49999545, 60);
    m[16] = pll(79999559, 80);
    m[17] = pll(9999573, 90);
    m[18] = pll(39999594, 10);
    m[19] = pll(69999608, 30);
    m[20] = pll(99999622, 50);
    m[21] = pll(29999636, 60);
    m[22] = pll(59999650, 80);
    m[23] = pll(89999664, 100);
    m[24] = pll(19999685, 10);
    m[25] = pll(49999699, 30);
    m[26] = pll(79999713, 50);
    m[27] = pll(9999727, 60);
    m[28] = pll(39999741, 80);
    m[29] = pll(69999755, 100);
    m[30] = pll(99999776, 20);
    m[31] = pll(29999790, 30);
    m[32] = pll(59999804, 50);
    m[33] = pll(89999818, 70);
    m[34] = pll(19999832, 80);
    m[35] = pll(49999846, 100);
    m[36] = pll(79999867, 20);
    m[37] = pll(9999881, 30);
    m[38] = pll(39999895, 50);
    m[39] = pll(69999909, 70);
    m[40] = pll(99999923, 90);
    m[41] = pll(29999937, 100);
    m[42] = pll(59999958, 20);
    m[43] = pll(89999972, 40);
    m[44] = pll(19999986, 50);
    m[45] = pll(50000000, 70);
    m[46] = pll(80000014, 90);
    m[47] = pll(10000028, 100);
    m[48] = pll(40000049, 20);
    m[49] = pll(70000063, 40);
    m[50] = pll(77, 50);
    m[51] = pll(30000091, 70);
    m[52] = pll(60000105, 90);
    m[53] = pll(90000126, 10);
    m[54] = pll(20000140, 20);
    m[55] = pll(50000154, 40);
    m[56] = pll(80000168, 60);
    m[57] = pll(10000182, 70);
    m[58] = pll(40000196, 90);
    m[59] = pll(70000217, 10);
    m[60] = pll(231, 20);
    m[61] = pll(30000245, 40);
    m[62] = pll(60000259, 60);
    m[63] = pll(90000273, 80);
    m[64] = pll(20000287, 90);
    m[65] = pll(50000308, 10);
    m[66] = pll(80000322, 30);
    m[67] = pll(10000336, 40);
    m[68] = pll(40000350, 60);
    m[69] = pll(70000364, 80);
    m[70] = pll(378, 90);
    m[71] = pll(30000399, 10);
    m[72] = pll(60000413, 30);
    m[73] = pll(90000427, 50);
    m[74] = pll(20000441, 60);
    m[75] = pll(50000455, 80);
    m[76] = pll(80000469, 100);
    m[77] = pll(10000490, 10);
    m[78] = pll(40000504, 30);
    m[79] = pll(70000518, 50);
    m[80] = pll(532, 60);
    m[81] = pll(30000546, 80);
    m[82] = pll(60000560, 100);
    m[83] = pll(90000581, 20);
    m[84] = pll(20000595, 30);
    m[85] = pll(50000609, 50);
    m[86] = pll(80000623, 70);
    m[87] = pll(10000637, 80);
    m[88] = pll(40000651, 100);
    m[89] = pll(70000672, 20);
    m[90] = pll(686, 30);
    m[91] = pll(30000700, 50);
    m[92] = pll(60000714, 70);
    m[93] = pll(90000728, 90);
    m[94] = pll(20000742, 100);
    m[95] = pll(50000763, 20);
    m[96] = pll(80000777, 40);
    m[97] = pll(10000791, 50);
    m[98] = pll(40000805, 70);
    m[99] = pll(70000819, 90);
    m[100] = pll(833, 100);

    cin >> prevH;
    prevH /= trailZ;
    // First block
    cout << msg << " " << m[prevH].first << endl;
    // Hash of first block
    prevH = m[prevH].second;
    // Second block
    cout << msg << " " << m[prevH].first << endl;
}