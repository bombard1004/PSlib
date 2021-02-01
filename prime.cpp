// prime.cpp
// author bombard1004
// last_update Feb 1 2021

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

class PrimeFactorization {
private:
    std::vector<std::pair<long long, int>> factors;
    long long n;

public:
    PrimeFactorization(long long _n) {
        n = _n;

        for(long long p : primes) {
            if(p * p > _n)
                break;
            
            int exponent = 0;
            while(_n % p == 0) {
                _n /= p;
                exponent++;
            }

            if(exponent != 0)
                factors.push_back(std::make_pair(p, exponent));
        }

        if(_n != 1)
            factors.push_back(std::make_pair(_n, 1));
    }

    long long eulerPhi() {
        long long ret = n;

        for(auto fp : factors)
            ret -= (ret / fp.first);
        
        return ret;
    }
};
