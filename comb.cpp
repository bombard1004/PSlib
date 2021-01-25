#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000
#define MAXR 10000

const int mod = 1e9 + 7;

long long comb[MAXN][MAXR];

long long getComb(int n, int r) {
    if(n < r) return 0;
    if(r == 0 || n == r) return 1;

    long long &ret = comb[n][r];
    if(ret != 0) return ret;
    
    return ret = (getComb(n-1, r-1) + getComb(n-1, r)) % mod;
}