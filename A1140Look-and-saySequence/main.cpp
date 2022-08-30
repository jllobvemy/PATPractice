#include <bits/stdc++.h>
// Accepted!
using namespace std;
string Describe(const string& s) {
    stringstream ss;
    if (s.size() == 1) {
        ss << s[0] << 1;
        return ss.str();
    }
    int cnt = 1;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == s[i - 1]) {
            cnt++;
        }
        else {
            ss << s[i - 1] << cnt;
            cnt = 1;
        }
    }
    ss << s.back() << cnt;
    return ss.str();
}
int main() {
    string D;
    int N;
    cin >> D >> N;
    while (--N) {
        D = Describe(D);
    }
    cout << D;
    return 0;
}
