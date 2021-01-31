// euclid.cpp
// author bombard1004
// last_update Jan 31 2021

#include <bits/stdc++.h>

std::pair<long long, long long> extendedEuclidean(long long A, long long B) {
    if(B == 0)
        return std::pair<long long, long long>{1, 0};
    
    auto p = extendedEuclidean(B, A%B);
    return std::pair<long long, long long>{p.second, p.first - (A/B) * p.second};
}

long long modInv(long long A, long long mod) {
    long long d = std::gcd(A, mod);
    if(d != 1)
        return -1;
    
    long long res = extendedEuclidean(A, mod).first % mod;
    if(res < 0) res += mod;

    return res;
}
