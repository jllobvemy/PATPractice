#include <bits/stdc++.h>
// Accepted!
using namespace std;

bool isPalindromic(const vector<int>& v) {
    for (auto i = 0; i < v.size() / 2; i++) {
        int last = v.size() - i - 1;
        if (v[i] != v[last]) return false;
    }
    return true;
}

vector<int> transRadix(long long val, int base) {
    vector<int> ret;
    while (val) {
        ret.push_back(val % base);
        val /= base;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}


int main() {
    int n;
    int b;
    cin >> n >> b;
    auto v = transRadix(n, b);
    if (isPalindromic(v)) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    bool first = true;
    for (int i = 0; i < v.size(); i++) {
        if (first) {
            first = false;
            cout << v[i];
        }
        else cout << " " << v[i];
    }
    return 0;
}
