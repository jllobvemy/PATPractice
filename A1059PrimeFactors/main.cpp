#include <bits/stdc++.h>
// Accepted!
using namespace std;
using ll = long long;
map<ll, ll> factors;

void Print(ll num, const map<ll,ll>& v) {
    cout << num << "=";
    bool first = true;
    for (const auto& n: v) {
        if (first) {
            cout << n.first;
            if (n.second != 1) {
                cout << "^" << n.second;
            }
            first = false;
        }
        else {
            cout << "*" << n.first;
            if (n.second != 1) {
                cout << "^" << n.second;
            }
        }
    }
}

void FindFactors(ll num) {
    ll last = sqrt(num) + 1;
    bool isprime = true;
    for (int i = 2; i < last; ++i) {
        if (num % i == 0) {
            if (factors.find(i) != factors.end()) {
                factors[i]++;
            }
            else {
                factors[i] = 1;
            }
            isprime = false;
            FindFactors(num / i);
            break;
        }
    }
    if (isprime) {
        if (factors.find(num) != factors.end()) {
            factors[num]++;
        }
        else {
            factors[num] = 1;
        }
    }
}

int main() {
    ll number;
    cin >> number;
    FindFactors(number);
    Print(number, factors);

    return 0;
}
