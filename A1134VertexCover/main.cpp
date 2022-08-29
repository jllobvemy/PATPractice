#include <bits/stdc++.h>
// Accepted!
using namespace std;
map<int, vector<pair<int, int>>> Edges;
map<pair<int, int>, int> Count;

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        Edges[a].push_back(pair(a, b));
        Edges[b].push_back(pair(b, a));
        Count[{a, b}] = 0;
        Count[{b, a}] = 0;
    }
    int K;
    cin >> K;
    vector<decltype(Count.begin())> Its;
    for (auto it = Count.begin(); it != Count.end(); it++) {
        Its.push_back(it);
    }
    for (int i = 0; i < K; ++i) {
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int m;
            cin >> m;
            for (auto [a, b]: Edges[m]) {
                Count[{a, b}]++;
                Count[{b, a}]++;
            }
        }
        bool flag = true;
        for (int j = 0; j < Its.size(); ++j) {
            if (Its[j]->second == 0) flag = false;
            if (Its[j]->second > 0) Its[j]->second = 0;
        }
        cout << (flag? "Yes": "No") << "\n";
    }

}
