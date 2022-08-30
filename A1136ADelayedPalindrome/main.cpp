#include <bits/stdc++.h>
// Not ac.
using namespace std;

bool judge(string& n) {
    for (int i = 0; i < n.size() / 2; ++i) {
        if (n[i] != n[n.size() - i - 1]) return false;
    }
    return true;
}

int main() {
    string n;
    cin >> n;
    char buf[1000];
    int cnt = 0;
    while (!judge(n)) {
        if (cnt++ >= 10) break;
        long long a = stoi(n);
        std::reverse(n.begin(), n.end());
        long long b = stoi(n);
        stringstream ss;
        ss << a + b;
        n = ss.str();
        sprintf(buf, "%lld + %lld = %s\n", a, b, n.c_str());
        cout << buf;
    }
    if (cnt < 11) {
        cout << n << " is a palindromic number." << endl;
    }
    else {
        cout << "Not found in 10 iterations." << endl;
    }
    return 0;
}
