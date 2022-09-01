#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 1010;
array<array<int, MAXLEN>, MAXLEN> G;
array<bool, MAXLEN> printed;
map<int, set<int>> callcount;
map<int, int> backcount;
vector<int> suspects;
vector<int> ans;
int K, N, M;

void FindGang(int n) {
    for (auto i: suspects)  {
        if (!printed[i]) {
            if (G[n][i] > 0 && G[i][n] > 0) {
                printed[i] = true;
                ans.push_back(i);
                FindGang(i);
            }
        }
    }
}

int main() {
    cin >> K >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        if (w == 0) return 1;
        G[a][b] += w;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; ++j) {
            if (G[i][j] <= 5 && G[i][j] > 0) {
                callcount[i].insert(j);
            }
        }
    }
    for (auto& [a, b]: callcount) {
        for (auto e: b) {
            if (G[e][a] > 0) {
                backcount[a]++;
            }
        }
    }
    for (auto& [i, s]: callcount) {
        if (s.size() > K) {
            if (backcount[i] * 1.0 / s.size() <= 0.2)
                suspects.push_back(i);
        }
    }
    sort(suspects.begin(), suspects.end());
    bool flag = true;
    for (auto e: suspects) {
        if (!printed[e]) {
            ans.clear();
            ans.push_back(e);
            printed[e] = true;
            FindGang(e);
            sort(ans.begin(), ans.end());
            bool first = true;
            for (auto i: ans) {
                flag = false;
                if (first) first = false;
                else cout << " ";
                cout << i;
            }
            cout << endl;
        }
    }
    if (flag) cout << "None" << endl;
    return 0;
}
