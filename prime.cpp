#include <bits/stdc++.h>

using namespace std;

vector<int> primes{2};
void getPrime(int n) {
    vector<bool> sieve(n+1);
    for(int p = 3; p <= n; p += 2) {
        if(!sieve[p]) {
            primes.push_back(p);
            for(int m = p; m <= n; m += 2 * p) sieve[m] = true;
        }
    }
}