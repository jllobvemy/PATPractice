#include <bits/stdc++.h>
// Accepted!
using namespace std;

class Rational {
public:
    long int nu; // up
    long int de; // down
    Rational operator+(const Rational& b) const {
        long int down = lcm(de, b.de);
        long int mul1 = down / de;
        long int mul2 = down / b.de;
        return {nu * mul1 + b.nu * mul2, down};
    }
    Rational(long int a, long int b): nu(a), de(b) {
        if (a > 0 && b < 0 || a < 0 && b < 0) {
            nu = -nu;
            de = -de;
        }
    }
};
void Foo(Rational& rational) {
    long int up = abs(rational.nu);
    long int t = gcd(up, rational.de);
    rational.de /= t; rational.nu /= t;
}

vector<Rational> r;

int main() {
    int N;
    cin >> N;
    r.reserve(N);
    char buf[100];
    for (int i = 0; i < N; ++i) {
        cin >> buf;
        long int up, down;
        sscanf(buf, "%ld/%ld", &up, &down);
        r.emplace_back(up, down);
    }
    for (int i = 1; i < N; ++i) {
        r[0] = r[i] + r[0];
    }
    Foo(r[0]);
    int left = r[0].nu / r[0].de;
    r[0].nu %= r[0].de;
    if (left != 0 && r[0].nu != 0) {
        cout << left << " " << r[0].nu << "/" << r[0].de;
    } else if (r[0].nu == 0){
        cout << left;
    } else {
        cout << r[0].nu << "/" << r[0].de;
    }
    return 0;
}
