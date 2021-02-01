// bigdec.cpp
// author bombard1004
// last_update Feb 1 2021

#include <bits/stdc++.h>

class BigDecimal {
private:
    std::vector<int> digits;
    bool sign;

public:
    BigDecimal(BigDecimal &bd) {
        digits = std::vector<int>(bd.digits.begin(), bd.digits.end());
        sign = bd.sign;
    }

    BigDecimal(long long x) {
        if(x < 0) {
            x = -x;
            sign = true;
        }
        else
            sign = false;

        if(x == 0)
            digits.push_back(0);
        
        while(x != 0) {
            digits.push_back(x % 10);
            x /= 10;
        }
    }

    BigDecimal(std::string &s) {
        auto endIt = s.rend();
        if(s[0] == '-') {
            endIt--;
            sign = true;
        }
        else
            sign = false;
        
        for(auto it = s.rbegin(); it != endIt; it++)
            digits.push_back(*it - '0');
    }

    std::vector<int> &getDigits() {
        return digits;
    }

    void print(char endc = '\n') {
        if(sign)
            printf("-");
        
        for(auto it = digits.rbegin(); it != digits.rend(); it++)
            printf("%d", *it);
        
        printf("%c", endc);
        return;
    }

    size_t length() {
        return digits.size();
    }

    void negate() {
        sign = !sign;
        return;
    }

    BigDecimal operator - () {
        BigDecimal ret = BigDecimal(*this);
        ret.negate();
        return ret;
    }
        
    bool operator == (BigDecimal &bd) {
        if(this->length() != bd.length()
        || sign != bd.sign)
            return false;
        
        int n = this->length();
        for(int i = 0; i < n; i++)
            if(digits[i] != bd.digits[i])
                return false;
        
        return true;
    }
    bool operator == (long long x) {
        BigDecimal bd(x);
        return *this == bd;
    }

    bool operator < (BigDecimal &bd) {
        if(sign != bd.sign) {
            return sign;
        }

        if(this->length() != bd.length())
            return (this->length() < bd.length()) ^ sign;
        
        int l = this->length();
        for(int i = l-1; i >= 0; i--) {
            if(digits[i] != bd.digits[i])
                return (digits[i] < bd.digits[i]) ^ sign;
        }

        return false;
    }

    BigDecimal operator + (BigDecimal &bd) {
        if(sign && bd.sign) {
            BigDecimal ng1 = -(*this);
            BigDecimal ng2 = -bd;
            return -(ng1 + ng2);
        }
        if(sign) {
            return bd - *this;
        }
        if(bd.sign) {
            return *this - bd;
        }

        std::vector<int> dg1(digits), dg2(bd.digits);
        int carry = 0;
        BigDecimal res(0); res.digits.pop_back();
        
        int longerL = std::max(dg1.size(), dg2.size());
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
    BigDecimal operator + (long long x) {
        BigDecimal bd(x);
        return *this + bd;
    }

    BigDecimal operator - (BigDecimal &bd) {
        if(*this < bd)
            return -(bd - *this);
        if(*this == bd)
            return BigDecimal(0);
        
        if(sign) {
            BigDecimal ng1 = (-bd);
            BigDecimal ng2 = -(*this);
            return ng1 - ng2;
        }
        if(bd.sign) {
            BigDecimal ng = -bd;
            return *this + ng;
        }

        std::vector<int> dg1(digits), dg2(bd.digits);
        int carry = 0;
        BigDecimal res(0); res.digits.pop_back();
        
        int longerL = std::max(dg1.size(), dg2.size());
        dg1.resize(longerL); dg2.resize(longerL);

        for(int i = 0; i < longerL; i++) {
            int d = dg1[i] - dg2[i] + carry;
            carry = -(int)(d < 0);
            res.digits.push_back((d+10) % 10);
        }
        while(res.digits.back() == 0)
            res.digits.pop_back();
        
        return res;
    }
    BigDecimal operator - (long long x) {
        BigDecimal bd(x);
        return *this - bd;
    }

    BigDecimal operator * (BigDecimal &bd) {
        BigDecimal res(0);
        BigDecimal zeroBD(0);
        BigDecimal tenBD(10);

        if(*this == zeroBD || bd == zeroBD) {
            return zeroBD;
        }
        else if(bd.length() == 1) {
            int carry = 0;
            res.digits.pop_back();
            
            int l = this->length();
            for(int i = 0; i < l; i++) {
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

        res.sign = sign ^ bd.sign;
        return res;
    }
    BigDecimal operator * (long long x) {
        BigDecimal bd(x);
        return *this * bd;
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
