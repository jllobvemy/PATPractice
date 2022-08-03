#include <bits/stdc++.h>
// Accepted!
using namespace std;

class BigNum {
    vector<short> _number;
public:
    explicit BigNum(const string& s) {
        for (const auto c: s) {
            _number.push_back(static_cast<short>(c - '0'));
        }
    }
    BigNum(const BigNum& o) {
        for (const auto i: o._number) {
            _number.push_back(i);
        }
    }
    BigNum& operator=(const BigNum& o) {
        _number.clear();
        for (const auto i: o._number) {
            _number.push_back(i);
        }
        return *this;
    }
    BigNum operator+(const BigNum& o) {
        BigNum base = _number.size() > o._number.size() ? *this: o;
        const BigNum& other = _number.size() > o._number.size() ? o: *this;
        auto itbase = base._number.rbegin();
        auto itother = other._number.rbegin();
        while (true) {
            *itbase += *itother;
            itbase++;
            itother++;
            if (itother == other._number.rend()) {
                break;
            }
        }
        short carry = 0;
        for (auto it = base._number.rbegin(); it != base._number.rend(); it++) {
            *it += carry;
            if (*it > 9)  {
                carry = *it / 10;
                *it %= 10;
            }
            else {
                carry = 0;
            }
        }
        if (carry > 0) {
            base._number.insert(base._number.begin(), carry);
        }
        return base;
    }
    friend bool isPalindromic(const BigNum& bigNum);
    friend BigNum Reverse(const BigNum& bigNum);
    friend ostream& operator<<(ostream& o, BigNum& bigNum) {
        for (auto i: bigNum._number) {
            cout << i;
        }
        return o;
    }
};

bool isPalindromic(const BigNum& bigNum) {
    auto itbegin = bigNum._number.begin();
    auto itend = bigNum._number.end() - 1;
    while (true) {
        if (*itbegin != *itend) {
            return false;
        }
        itbegin++;
        itend--;
        if (itbegin >= itend) return true;
    }
}

BigNum Reverse(const BigNum& bigNum) {
    BigNum ret = bigNum;
    std::reverse(ret._number.begin(), ret._number.end());
    while(*ret._number.begin() == 0) {
        ret._number.erase(ret._number.begin());
    }
    return ret;
}

int main() {
    string s;
    int n;
    cin >> s >> n;
    BigNum b(s);
    int step = 0;
    while (step < n && !isPalindromic(b)) {
        b = b + Reverse(b);
        step++;
    }
    cout << b << endl << step;
}
