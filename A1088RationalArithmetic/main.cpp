#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct Rational {
    long long up, down;
    int flag = 1;
    Rational(long long a, long long b): up(abs(a)), down(abs(b)){
        if (a < 0) flag = -1;
        if (b == 0) {
            up = LONG_MAX;
            down = 1;
        }
        long long g = gcd(up, down);
        up /= g; down /= g;
    }
    string to_string() const {
        if (up >= LONG_MAX) return "Inf";
        if (up == 0) return "0";
        string buf;
        if (flag == -1) buf += "(-";
        long long left = up / down;
        if (down != 1)
            if (left == 0) {
                buf += std::to_string(up);
                buf += '/';
                buf += std::to_string(down);
            } else {
                buf += std::to_string(left);
                buf += ' ';
                buf += std::to_string(up % down);
                buf += '/';
                buf += std::to_string(down);
            }
        else buf += std::to_string(up);
        if (flag == -1) buf += ')';
        return buf;
    }
    Rational operator+(const Rational& b) const {
        long long tmpdown = lcm(down, b.down);
        long long tmp1 = tmpdown / down;
        long long tmp2 = tmpdown / b.down;
        return Rational{tmp1 * up * flag + tmp2 * b.up * b.flag, tmpdown};
    }
    Rational operator-(const Rational& b) const {
        long long tmpdown = lcm(down, b.down);
        long long tmp1 = tmpdown / down;
        long long tmp2 = tmpdown / b.down;
        return Rational{tmp1 * up * flag - tmp2 * b.up * b.flag, tmpdown};
    }
    Rational operator*(const Rational& b) const {
        return Rational{up * b.up * flag * b.flag, down * b.down};
    }
    Rational operator/(const Rational& b) const {
        if (b.up == 0) return {LONG_MAX, 1};
        Rational tmp{b.down, b.up};
        if (b.flag == -1) tmp.flag = -1;
        return *this * tmp;
    }
};
int main() {
    char buf[100];
    cin.getline(buf, 100);
    long long a1, b1, a2, b2;
    sscanf(buf, "%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    Rational r1{a1, b1}, r2{a2, b2};
    cout << r1.to_string() << " + " << r2.to_string() << " = " << (r1 + r2).to_string() << endl;
    cout << r1.to_string() << " - " << r2.to_string() << " = " << (r1 - r2).to_string() << endl;
    cout << r1.to_string() << " * " << r2.to_string() << " = " << (r1 * r2).to_string() << endl;
    cout << r1.to_string() << " / " << r2.to_string() << " = " << (r1 / r2).to_string() << endl;
    return 0;
}
