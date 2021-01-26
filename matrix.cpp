// matrix.cpp
// author bombard1004
// last_update Jan 27 2021

#include <bits/stdc++.h>

class Matrix {
private:
    std::pair<int, int> msize;
    std::vector<std::vector<long long>> mat;

public:
    Matrix(int R, int C) {
        msize.first = R; msize.second = C;
        mat = std::vector<std::vector<long long>>(R, std::vector<long long>(C));
    }

    Matrix(int R, int C, std::vector<long long> &arr) {
        if(R * C != arr.size()) {
            msize.first = msize.second = 0;
            return;
        }

        msize.first = R; msize.second = C;
        mat = std::vector<std::vector<long long>>(R, std::vector<long long>(C));

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

    std::pair<int, int> &getSize() {
        return msize;
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

    std::vector<long long> & operator [] (int idx) {
        return mat[idx];
    }
};

class SquareMatrix : public Matrix {
public:
    SquareMatrix(int n):
        Matrix(n, n)
    {}
};

SquareMatrix eye(int n) {
    SquareMatrix ret(n);
    for(int i = 0; i < n; i++)
        ret[i][i] = 1;
    
    return ret;
}

long long det(SquareMatrix &sqm) {
    int n = sqm.getSize().first;
    std::vector<int> Permut(n);
    for(int i = 0; i < n; i++)
        Permut[i] = i;

    long long res = 0;
    do {
        int inversions = 0;
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(Permut[i] > Permut[j]) inversions++;
        
        long long temp = 1;
        for(int i = 0; i < n; i++)
            temp *= sqm[i][Permut[i]];
        
        res += (inversions % 2 ? -temp : temp);
    } while(std::next_permutation(Permut.begin(), Permut.end()));

    return res;
}
