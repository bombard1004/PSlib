// matrix.cpp
// author bombard1004
// last_update Jan 28 2021

#include <bits/stdc++.h>

class Matrix;
class SquareMatrix;
class Column;

SquareMatrix eye(int n);
long long det(SquareMatrix &sqm);
std::pair<bool, Column> Cramer(SquareMatrix &A, Column &b);

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

    Matrix operator % (unsigned long long mod) {
        Matrix ret(msize.first, msize.second);

        for(int i = 0; i < msize.first; i++) {
            for(int j = 0; j < msize.second; j++) {
                ret[i][j] = mat[i][j] % mod;
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

    SquareMatrix(int n, std::vector<long long> &arr):
        Matrix(n, n, arr)
    {}

    Matrix power(long long exponent, unsigned long long mod = 0) {
        if(exponent == 0)
            return eye(this->getSize().first);
        
        Matrix halfpower = power(exponent/2, mod);

        if(exponent % 2) {
            if(mod == 0) return halfpower * halfpower * *this;
            else return (halfpower * halfpower % mod) * *this % mod;
        }
        else {
            if(mod == 0) return halfpower * halfpower;
            else return halfpower * halfpower % mod;
        }
    }
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

class Column : public Matrix {
public:
    Column(int n):
        Matrix(n, 1)
    {}

    Column(int n, std::vector<long long> &arr):
        Matrix(n, 1, arr)
    {}
};

std::pair<bool, Column> Cramer(SquareMatrix &A, Column &b) {
    int n1 = A.getSize().first, n2 = b.getSize().first;
    if(n1 != n2)
        return std::make_pair(false, Column(0));
    int n = n1;

    long long detA = det(A);
    std::vector<long long> originalCol(n);

    if(detA == 0) {
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                originalCol[i] = A[i][j];
                A[i][j] = b[i][0];
            }
            
            long long detAj = det(A);

            for(int i = 0; i < n; i++)
                A[i][j] = originalCol[i];
            
            if(detAj != 0)
                return std::make_pair(false, Column(0));
        }

        return std::make_pair(true, Column(0));
    }
    else {
        Column res(n);
        
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < n; i++) {
                originalCol[i] = A[i][j];
                A[i][j] = b[i][0];
            }
            
            long long detAj = det(A);

            for(int i = 0; i < n; i++)
                A[i][j] = originalCol[i];
            
            res[j][0] = detAj / detA;
        }

        return std::make_pair(true, res);
    }
}