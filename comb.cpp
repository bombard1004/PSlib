// comb.cpp
// author bombard1004
// last_update Jan 27 2021

#include <bits/stdc++.h>

std::vector<std::vector<long long>> comb{ std::vector<long long>{ 1LL } };
long long getComb(int n, int r, unsigned long long mod = 0) {
    if(n < r) return 0LL;
    if(r == 0 || n == r) return 1LL;
    if(r > n-r) return getComb(n, n-r, mod);

    if(n >= comb.size()) {
        for(int t = comb.size() + 1; t <= n+1; t++) {
            std::vector<long long> v((t+1)/2);
            v[0] = 1LL;
            comb.push_back(v);
        }
    }

    long long &ret = comb[n][r];
    if(ret != 0LL) return ret;
    
    ret = (getComb(n-1, r-1, mod) + getComb(n-1, r, mod));
    if(mod) ret %= mod;
    
    return ret;
}
