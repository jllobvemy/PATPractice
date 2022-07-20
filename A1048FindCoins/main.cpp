#include <bits/stdc++.h>
// AC!
using namespace std;
map<int, int> coinNumMap;
int N, M;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        if (coinNumMap.find(tmp) != coinNumMap.end()) {
            coinNumMap[tmp]++;
        }
        else {
            coinNumMap[tmp] = 1;
        }
    }
    auto first = coinNumMap.end();
    auto second = coinNumMap.end();
    for (auto left = coinNumMap.begin(); left != coinNumMap.end(); left++) {
        int leftneed = M - left->first;
        left->second--;
        auto right = coinNumMap.find(leftneed);
        if (right != coinNumMap.end()) {
            if (right->second <= 0)
                continue;
            else {
                first = left;
                second = right;
                break;
            }
        }
    }
    if (first != coinNumMap.end()) {
        cout << first->first << " " << second->first;
    }
    else {
        cout << "No Solution";
    }
    return 0;
}
