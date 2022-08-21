#include <bits/stdc++.h>
// Accepted! Bad code.
using namespace std;
string READNUM[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"};
string READRADIX[] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
const string& CToRead(char c) {
    return READNUM[c - '0'];
}

vector<string> PronounceShi(string n) {
    vector<string> ret;
    if (n.size() == 1) {
        ret.emplace_back(CToRead(n[0]));
        return ret;
    }
    if (n[0] == '0' && n[1] != '0') {  // 01
        ret.push_back(READNUM[0]);
        ret.push_back(CToRead(n[1]));
    }
    if (n[1] == '0' && n[0] != '0') { // 10
        ret.push_back(CToRead(n[0]));
        ret.push_back(READRADIX[0]);
    }
    if (n[0] != '0' && n[1] != '0') { // 11
        ret.push_back(CToRead(n[0]));
        ret.push_back(READRADIX[0]);
        ret.push_back(CToRead(n[1]));
    }
    return ret;
}

vector<string> PronounceBai(string n) {
    string sub = n.substr(1);
    vector<string> ret;
    if (n[0] == '0') {
        ret = PronounceShi(sub);
        if (ret[0] != "ling") {
            ret.insert(ret.begin(), "ling");
        }
        return ret;
    }
    else {
        ret.push_back(CToRead(n[0]));
        ret.push_back(READRADIX[1]);
        auto tmp = PronounceShi(sub);
        ret.insert(ret.end(), tmp.begin(), tmp.end());
        return ret;
    }
}

vector<string> PronounceQian(string n) {
    string sub = n.substr(1);
    vector<string> ret;
    if (n.size() == 3) return PronounceBai(n);
    if (n.size() <= 2) return PronounceShi(n);
    if (n[0] == '0') {
        ret = PronounceBai(sub);
        if (ret[0] != "ling") {
            ret.insert(ret.begin(), "ling");
        }
        return ret;
    }
    else {
        ret.push_back(CToRead(n[0]));
        ret.push_back(READRADIX[2]);
        auto tmp = PronounceBai(sub);
        ret.insert(ret.end(), tmp.begin(), tmp.end());
        return ret;
    }
}

int main() {
    string n;
    cin >> n;
    vector<string> ans;
    if (n[0] == '-') {
        ans.emplace_back("Fu");
        n = n.substr(1);
    }
    if (n.size() == 9) {
        ans.push_back(CToRead(n[0]));
        ans.emplace_back("Yi");
        auto tmp = PronounceQian(n.substr(1));
        ans.insert(ans.end(), tmp.begin(), tmp.end());
        ans.emplace_back("Wan");
        tmp = PronounceQian(n.substr(5));
        ans.insert(ans.end(), tmp.begin(), tmp.end());
    }
    else if (n.size() <= 8 && n.size() > 4) {
        auto tmp = PronounceQian(n.substr(0, n.size() - 4));
        ans.insert(ans.end(), tmp.begin(), tmp.end());
        ans.emplace_back("Wan");
        tmp = PronounceQian(n.substr(n.size() - 4, n.size()));
        ans.insert(ans.end(), tmp.begin(), tmp.end());
    }
    else if (n.size() <= 4) {
        try {
            auto tmp = PronounceQian(n);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        catch (...) {
            return 1;
        }
    }

    bool first = true;
    for (auto& e: ans) {
        if (first) {
            cout << e;
            first = false;
        }
        else cout << " " << e;
    }
    return 0;
}
