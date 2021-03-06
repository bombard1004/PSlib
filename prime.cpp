// prime.cpp
// author bombard1004
// last_update Mar 7 2021

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
    std::map<long long, int> _factors;

public:
    PrimeFactorization(const PrimeFactorization &pf) {
        _factors = std::map<long long, int>(pf._factors);
    }

    PrimeFactorization(long long n) {
        for(long long p : primes) {
            if(p * p > n)
                break;
            
            while(n % p == 0) {
                n /= p;
                _factors[p]++;
            }
        }

        if(n != 1)
            _factors[n] = 1;
    }

    std::vector<long long> getFactors() const {
        std::vector<long long> ret;
        for(auto it = _factors.begin(); it != _factors.end(); it++)
            ret.push_back(it->first);
        
        return ret;
    }

    void mulPrime(long long prime, int exponent = 1) {
        _factors[prime] += exponent;
        return;
    }

    int exponentOf(long long prime) const {
        auto it = _factors.find(prime);
        if(it == _factors.end()) return 0;
        else return it->second;
    }
};

long long eulerPhi(long long n) {
    long long ret = n;
    std::vector<long long> _factors = PrimeFactorization(n).getFactors();

    for(long long factor : _factors)
        ret -= (ret / factor);
        
    return ret;
}
