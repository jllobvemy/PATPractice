#include <bits/stdc++.h>
// Accepted!
using namespace std;
map<char, int> Prior;

bool cmp(char a, char b) {
    return Prior[a] < Prior[b];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    set<char> set1, set2;
    int p = 0;
    for (char c: s1) {
        char C = toupper(c);
        if (Prior.find(C) == Prior.end()) {
            Prior[C] = p++;
        }
        set1.insert(C);
    }
    for (char c: s2) {
        set2.insert(toupper(c));
    }
    vector<char> res;
    set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(res));
    sort(res.begin(), res.end(), cmp);
    for (auto c: res) {
        cout << c;
    }
    return 0;
}
