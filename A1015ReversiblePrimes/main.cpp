#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> values;

bool is_prime(int x) {
    if (x == 0 || x == 2) return true;
    if (x == 1) return false;
    int last = sqrt(x) + 1;
    for (int i = 2; i <= last; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int reverse_int(int x, int radix) {
    string tmp;
    while (x) {
        tmp += to_string(x % radix);
        x /= radix;
    }
    if (tmp.empty()) tmp = "0";
    int ret = stoi(tmp, nullptr, radix);
    return ret;
}


int main() {
    int tmp;
    while (true) {
        cin >> tmp;
        if (tmp > 0) {
            int b;
            cin >> b;
            values.emplace_back(tmp, b);
        }
        else {
            break;
        }
    }
    for (const auto& i: values) {
        if (is_prime(i.first) && is_prime(reverse_int(i.first, i.second)))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
