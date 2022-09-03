#include <bits/stdc++.h>
using namespace std;
int judge(string &s) {
    int ans = 0;
    if (s.front() == 'f') ans += -2;
    if (s.back() == 'a') ans += -1;
    regex base(R"(([a-z])\1{5,})");
    auto Begin = s.cbegin();
    smatch res;
    while (regex_search(Begin, s.cend(), res, base)) {
        ans += 3;
        Begin = res.suffix().first;
    }
    regex base2("a[eh]");
    Begin = s.cbegin();
    while (regex_search(Begin, s.cend(), res, base2)) {
        ans += -4;
        Begin = res.suffix().first;
    }
    int right = 1;
    int cnt = 1;
    while (right < s.size()) {
        while (right < s.size() && s[right - 1] == s[right] - 1) {
            cnt++;
            right++;
        }
        if (cnt > 0) {
            if (cnt > 3) {
                ans += 5;
            }
            cnt = 1;
        }
        right++;
    }
    return ans;
}

int main() {
    int N, T, K;
    cin >> N >> T >> K;
    cin.get();
    while (K--) {
        string s;
        getline(cin, s);
        int n = judge(s);
        cout << n;
        if (n > T) cout << "!!!";
        cout << endl;
    }

    return 0;
}
