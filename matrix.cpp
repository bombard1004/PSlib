#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<long long>> matrix;

matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

matrix eye(int n) {
    matrix c(n, vector<long long>(n));
    for(int i = 0; i < n; i++) c[i][i] = 1;
    return c;
}