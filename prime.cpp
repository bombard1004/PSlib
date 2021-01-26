// prime.cpp
// author bombard1004
// last_update Jan 27 2021

#include <bits/stdc++.h>

std::vector<long long> primes{2};
void getPrime(long long n) {
    std::vector<bool> sieve(n+1);
    long long p = 3;
    for(long long p = 3; p <= n; p += 2) {
        if(!sieve[p]) {
            primes.push_back(p);
            for(long long m = p * p; m <= n; m += 2 * p) sieve[m] = true;
        }
    }
}
