#include <bits/stdc++.h>
using namespace std;
#define int long long int

// Note: 0 subMask not included

// O(2^setBits)
void submaskEnumeration(int mask) {
    for(int subMask = mask; subMask; subMask = (subMask - 1) & mask) {
        // Use subMask
    }
}

// O(3^bits)
void allSubmaskEnumeration(int mask) {
    int n;
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int subMask = mask; subMask; subMask = (subMask - 1) & mask) {
            // Use subMask
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
