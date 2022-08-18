#include <bits/stdc++.h>
using namespace std;
map<char, char> CMapping {{'1', '@'}, {'0', '%'}, {'l', 'L'}, {'O', 'o'}};
bool Modify(string& s) {
    bool ret = false;
    for (auto& c: s) {
        if (CMapping.find(c) != CMapping.end()) {
            c = CMapping[c];
            ret = true;
        }
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    vector<pair<string, string>> passwd;
    passwd.reserve(N);
    for (int i = 0; i < N; ++i) {
        string uname, passwdtmp;
        cin >> uname >> passwdtmp;
        passwd.emplace_back(uname, passwdtmp);
    }
    vector<pair<string, string>> ans;
    for (auto& e: passwd) {
        bool ret = Modify(e.second);
        if (ret) {
            ans.push_back(e);
        }
    }
    if (ans.empty() && N > 1) {
        cout << "There are " << N << " accounts and no account is modified";
        return 0;
    }
    if (ans.empty() && N == 1) {
        cout << "There is " << N << " account and no account is modified";
        return 0;
    }
    cout << ans.size() << endl;
    for (auto& e: ans) {
        cout << e.first << " " << e.second << endl;
    }
    return 0;
}
