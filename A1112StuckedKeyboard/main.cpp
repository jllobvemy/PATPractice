#include <bits/stdc++.h>
// Accepted!
using namespace std;
int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;
    list<char> slist;
    set<char> allKey;
    map<char, int> KeyCount;
    set<char> PerfectKey;
    for (char & i : s) {
        slist.push_back(i);
        allKey.insert(i);
        KeyCount[i]++;
    }
    for (auto k: KeyCount) {
        if (k.second % N) PerfectKey.insert(k.first);
    }
    int left = 0, right = 1;
    if (s[left] != s[right]) PerfectKey.insert(s[left]);
    bool findTrunk = false;
    vector<list<char>::iterator> NeedRemovedIt;
    while (left < right && right <= s.size()) {
        if (left != 0 && !findTrunk) {
            if (s[left - 1] != s[left] && s[left] != s[right]) {
                PerfectKey.insert(s[left]);
            }
        }
        if (s[left] != s[right] && !findTrunk) {
            left++;
            right++;
        }
        else if (s[left] == s[right] && right < s.size()){
            right++;
            findTrunk = true;
            continue;
        }
        if (findTrunk) {
            if ((right - left) % N) {
                PerfectKey.insert(s[left]);
                findTrunk = false;
            }
            right++;
            left = right - 1;
        }
    }
    left = 0;
    right = 1;
    while (left < right && right <= s.size()) {
        if (s[left] != s[right] && !findTrunk) {
            left++;
            right++;
        }
        else if (s[left] == s[right] && right < s.size()){
            right++;
            findTrunk = true;
            continue;
        }
        if (findTrunk) {
            if (PerfectKey.find(s[left]) == PerfectKey.end()) {
                int cnt = 0;
                while (left < right) {
                    cnt++;
                    auto tmp = slist.begin();
                    for (auto i = 0; i < left; i++) tmp++;
                    NeedRemovedIt.push_back(tmp);
                    left++;
                }
                int pnum = cnt / N;
                while (pnum--) {
                    NeedRemovedIt.pop_back();
                }
                while (cnt % N) {
                    cnt--;
                    NeedRemovedIt.pop_back();
                }
            }
            right++;
            left = right - 1;
        }
    }
    for (auto it: NeedRemovedIt) {
        slist.erase(it);
    }
    vector<char> ans;
    set_difference(allKey.begin(), allKey.end(), PerfectKey.begin(), PerfectKey.end(), back_inserter(ans));
    set<char> tmp;
    for (auto c: s) {
        if (tmp.find(c) == tmp.end())
            if (std::find(ans.begin(), ans.end(), c) != ans.end())  {
                cout << c;
                tmp.insert(c);
            }
    }
    cout << endl;
    for (auto i: slist) {
        cout << i;
    }
    return 0;
}
