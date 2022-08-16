#include <bits/stdc++.h>
// Accepted!
constexpr int MAXLEN = 1050;
using namespace std;
array<array<bool, MAXLEN>, MAXLEN> dp;

int main() {
    string s;
    getline(cin, s);
    int ans = 1;
    for (int i = 0; i < s.length(); ++i) {
        dp[i][i] = true;
        if (i < s.length() - 1) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans = 2;
            }
        }
    }
    for (int len = 3; len <= s.length(); ++len) {
        for (int i = 0; i + len - 1 < s.length(); ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = dp[i + 1][j - 1];
                ans = len;
            }
        }
    }
    cout << ans;
    return 0;
}
