#include <bits/stdc++.h>
using namespace std;
#define int long long int

namespace number_theory {
    bool isPrime(int n) {
        for(int i = 2; i * i <= n; i++)
            if(n % i == 0)
                return false;
        return true;
    }
    vector<int> divisors(int n) {
        vector<int> res;
        for(int i = 2; i * i <= n; i++)
            if(n % i == 0)
                res.push_back(i);
        for(int i = sqrt(n); i > 1; i--)
            if(n % i == 0 && n/i != res.back())
                res.push_back(n/i);
        if(n > 1)
            res.push_back(n);
        return res;
    }
    vector<int> primeFactors(int n) {
        vector<int> res;
        for(int i = 2; i * i <= n; i++) {
            if(n % i) continue;
            res.push_back(i);
            while(n % i == 0)
                n /= i;
        }
        if(n > 1)
            res.push_back(n);
        return res;
    }  
    map<int, int> factorize(int n) {
        map<int, int> res;
        for(int i = 2; i * i <= n; i++) {
            if(n % i) continue;
            res[i] = 0;
            while(n % i == 0)
                n /= i, res[i]++;
        }
        if(n > 1)
            res[n]++;
        return res;
    }
} using namespace number_theory;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << isPrime(7) << '\n';
    for(auto it: divisors(12))
        cout << it << " ";
    cout << '\n';
    for(auto it: primeFactors(102))
        cout << it << " ";
    cout << '\n';
    for(auto [key, freq]: factorize(204))
        cout << key << ": " << freq << '\n';
    cout << '\n';
    return 0;
}
