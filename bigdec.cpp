#include <bits/stdc++.h>

using namespace std;

class BigDecimal {
private:
    vector<int> digits;

public:
    BigDecimal(unsigned long long x) {
        if(x == 0)
            digits.push_back(0);
        
        while(x != 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
    }

    vector<int> &getDigits() {
        return digits;
    }

    void print() {
        for(auto it = digits.rbegin(); it != digits.rend(); it++)
            printf("%d", *it);
        
        puts("");
        return;
    }

    bool operator == (BigDecimal &bd) {
        if(digits.size() != bd.digits.size())
            return false;
        
        int n = digits.size();
        for(int i = 0; i < n; i++)
            if(digits[i] != bd.digits[i])
                return false;
        
        return true;
    }

    BigDecimal operator + (BigDecimal &bd) {
        vector<int> dg1(digits), dg2(bd.digits);
        int carry = 0;
        BigDecimal res(0); res.digits.pop_back();
        
        int longerL = max(dg1.size(), dg2.size());
        dg1.resize(longerL); dg2.resize(longerL);

        for(int i = 0; i < longerL; i++) {
            int d = dg1[i] + dg2[i] + carry;
            carry = (int)(d >= 10);
            res.digits.push_back(d % 10);
        }
        if(carry)
            res.digits.push_back(1);
        
        return res;
    }

    BigDecimal operator * (BigDecimal &bd) {
        BigDecimal res(0);
        BigDecimal zeroBD(0);
        BigDecimal tenBD(10);

        if(bd == zeroBD) {
            return zeroBD;
        }
        else if(bd.digits.size() == 1) {
            int carry = 0;
            res.digits.pop_back();
            
            for(int i = 0; i < digits.size(); i++) {
                int d = digits[i] * bd.digits[0] + carry;
                carry = d / 10;
                res.digits.push_back(d % 10);
            }

            if(carry)
                res.digits.push_back(carry);
        }
        else if(bd == tenBD) {
            res = res + *this;
            res.digits.insert(res.digits.begin(), 0);
        }
        else {
            BigDecimal ones(bd.digits[0]);
            BigDecimal divBy10 = bd + zeroBD;
            divBy10.digits.erase(divBy10.digits.begin());

            BigDecimal t1 = *this * ones;
            BigDecimal t2 = *this * divBy10 * tenBD;
            
            res = t1 + t2;
        }

        return res;
    }

    BigDecimal power(long long exponent) {
        if(exponent == 0)
            return BigDecimal(1);
        
        BigDecimal halfpower = power(exponent/2);
        
        if(exponent % 2)
            return halfpower * halfpower * *this;
        else
            return halfpower * halfpower;
    }
};