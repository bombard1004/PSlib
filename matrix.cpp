// bigdec.cpp
// author: bombard1004
// last_update Jan 26 2021

#include <bits/stdc++.h>

using namespace std;

class Matrix {
private:
    pair<int, int> msize;
    vector<vector<long long>> mat;

public:
    Matrix(int R, int C) {
        msize.first = R; msize.second = C;
        mat = vector<vector<long long>>(R, vector<long long>(C));
    }

    Matrix(int R, int C, vector<long long> &arr) {
        if(R * C != arr.size()) {
            msize.first = msize.second = 0;
            return;
        }

        msize.first = R; msize.second = C;
        mat = vector<vector<long long>>(R, vector<long long>(C));

        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                mat[i][j] = arr[C*i + j];
            }
        }
    }

    void print() {
        for(auto &row : mat) {
            for(long long x : row)
                printf("%lld ", x);

            puts("");
        }
    }

    void setFromInput() {
        for(int i = 0; i < msize.first; i++)
            for(int j = 0; j < msize.second; j++)
                scanf("%lld", &mat[i][j]);
    }

    Matrix operator * (const Matrix &rhs) {
        if(msize.second != rhs.msize.first)
            return Matrix(0, 0);
        
        Matrix ret(msize.first, rhs.msize.second);

        for(int i = 0; i < msize.first; i++) {
            for(int j = 0; j < rhs.msize.second; j++) {
                for(int k = 0; k < msize.second; k++) {
                    ret.mat[i][j] += mat[i][k] * rhs.mat[k][j];
                }
            }
        }
        
        return ret;
    }

    vector<long long> & operator [] (int idx) {
        return mat[idx];
    }
};

Matrix eye(int n) {
    Matrix ret(n, n);
    for(int i = 0; i < n; i++)
        ret[i][i] = 1;
    
    return ret;
}