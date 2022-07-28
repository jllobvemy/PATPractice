#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> diamonds;
vector<pair<int, int>> ans;


int main() {
    cin >> N >> M;
    diamonds.reserve(N);
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        diamonds.push_back(tmp);
    }
    auto pleft = diamonds.begin();
    auto pright = diamonds.begin();
    int currentSum = *pleft;
    int minLoss = INT_MAX;
    while (true) {
        if (pleft == diamonds.end() || (currentSum < M && pright == diamonds.end()))
            break;
        if (currentSum - M >= 0 && currentSum - M < minLoss) {
            minLoss = currentSum - M;
            ans.clear();
        }
        if (currentSum - M > minLoss) {
            currentSum -= *pleft;
            pleft++;
        }
        if (currentSum - M < minLoss && pright != diamonds.end()) {
            pright++;
            if (pright != diamonds.end())
                currentSum += *pright;
        }
        if (currentSum - M == minLoss) {
            ans.emplace_back(pleft - diamonds.begin() + 1, pright - diamonds.begin() + 1);
            currentSum -= *pleft;
            pleft++;
        }
    }
    for (auto it = ans.begin(); it != ans.end(); it++) {
        if (it == ans.begin())
            cout << it->first << "-" << it->second;
        else
            cout << endl << it->first << "-" << it->second;
    }
    return 0;
}
