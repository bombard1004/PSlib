// bigdec.cpp
// author bombard1004
// last_update Feb 7 2021

#include <bits/stdc++.h>

class BigDecimal {
private:
    std::vector<int> digits;
    bool sign;

public:
    BigDecimal(const BigDecimal &bd) {
        digits = std::vector<int>(bd.digits);
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

    BigDecimal(const std::string &s) {
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

    const std::vector<int> &getDigits() const {
        return digits;
    }

    void print(char endc = '\n') const {
        if(sign)
            printf("-");
        
        for(auto it = digits.rbegin(); it != digits.rend(); it++)
            printf("%d", *it);
        
        printf("%c", endc);
        return;
    }

    size_t length() const {
        return digits.size();
    }

    void negate() {
        sign = !sign;
        return;
    }

    BigDecimal tenfold() const {
        if(!(*this))
            return BigDecimal(0);

        BigDecimal ret(*this);
        ret.digits.insert(ret.digits.begin(), 0);
        
        return ret;
    }

    BigDecimal tenth() const {
        if(this->length() == 1)
            return BigDecimal(0);
        
        BigDecimal ret(*this);
        ret.digits.erase(ret.digits.begin());
        
        return ret;
    }

    BigDecimal operator - () const {
        BigDecimal ret = BigDecimal(*this);
        ret.negate();
        return ret;
    }

    bool operator ! () const {
        return (digits.size() == 1 && digits[0] == 0 && !sign);
    }
        
    bool operator == (const BigDecimal &bd) const {
        if(this->length() != bd.length()
        || sign != bd.sign)
            return false;
        
        int n = this->length();
        for(int i = 0; i < n; i++)
            if(digits[i] != bd.digits[i])
                return false;
        
        return true;
    }
    bool operator == (long long x) const {
        BigDecimal bd(x);
        return *this == bd;
    }

    bool operator < (const BigDecimal &bd) const {
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

    BigDecimal operator + (const BigDecimal &bd) const {
        if(sign && bd.sign)
            return -(-(*this) + -bd);
        if(sign)
            return bd - -(*this);
        if(bd.sign)
            return *this - -bd;

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
    BigDecimal operator + (long long x) const {
        return *this + BigDecimal(x);
    }

    BigDecimal operator - (const BigDecimal &bd) const {
        if(*this < bd)
            return -(bd - *this);
        if(*this == bd)
            return BigDecimal(0);
        
        if(sign) {
            return -bd - -(*this);
        }
        if(bd.sign) {
            return *this + -bd;
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
    BigDecimal operator - (long long x) const {
        return *this - BigDecimal(x);
    }

    BigDecimal operator * (const BigDecimal &bd) const {
        BigDecimal tenBD(10);

        if(!(*this) || !bd) {
            return BigDecimal(0);
        }

        if(this->sign && bd.sign)
            return (-*this) * (-bd);
        if(this->sign)
            return -((-*this) * bd);
        if(bd.sign)
            return -(*this * (-bd));

        if(bd.length() == 1) {
            BigDecimal res(0);
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
            
            return res;
        }
        else if(bd == BigDecimal(10)) {
            return this->tenfold();
        }
        else {
            return
                   *this * bd.digits[0]
                + (*this * bd.tenth()).tenfold();
        }
    }
    BigDecimal operator * (long long x) {
        return *this * BigDecimal(x);
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
