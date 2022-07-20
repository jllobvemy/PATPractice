#include <bits/stdc++.h>
using namespace std;

vector<int> s1;
set<char> s2;


int main() {
    char tmp;
    while ((tmp = getchar()) != '\n') {
        s1.push_back(tmp);
    }
    while ((tmp = getchar()) != '\n') {
        s2.insert(tmp);
    }
    for (auto c: s2) {
        for (int i = 0; i < s1.size(); ++i) {
            if (c == s1[i]) {
                s1[i] = -1;
            }
        }
    }
    for (auto c: s1) {
        if (c > 0)  printf("%c", c);
    }
    return 0;
}
