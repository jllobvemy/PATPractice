#include <bits/stdc++.h>
using namespace std;
constexpr int dis = 'a' - 'A';
bool endoffile = false;
void lowercase(char& c) {
    if (c >= 'A' && c <= 'Z') c += dis;
}
string eat() {
    stringstream ss;
    char c;
    do {
        cin.get(c);
        if (c == '\n') {
            endoffile = true;
            return "";
        }
        if (!isalnum(c)) continue;
        else break;
    } while(true);
    do {
        if (!isalnum(c)) break;
        lowercase(c);
        ss << c;
        cin.get(c);
        if (c == '\n') {
            endoffile = true;
            break;
        }
    } while (true);
    string s = ss.str();
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    string s;
    map<string, int> count;
    string tmp;
    while (!endoffile) {
        tmp = eat();
        if (tmp.empty()) continue;
        if (count.find(tmp) == count.end()) {
            count[tmp] = 1;
        }
        else {
            count[tmp]++;
        }
    }
    int max = -1;
    string ans;
    for (const auto& e: count) {
        if (e.second > max) {
            max = e.second;
            ans = e.first;
        }
        else if (e.second == max) {
            ans = ans < e.first ? ans: e.first;
        }
    }
    cout << ans << " " << max;
    return 0;
}
