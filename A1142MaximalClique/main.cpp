#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 210;
array<array<bool, MAXLEN>, MAXLEN> G;
int N, M;
int judge(vector<int>& v) {
    // -1: Not a Clique
    // 0: Not Maximal
    // 1: Clique
    vector<bool> flag(MAXLEN, false);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            if (!G[v[i]][v[j]])
                return -1;
        }
        flag[v[i]] = true;
    }
//    vector<vector<int>> a(v.size());
//    for (int i = 0; i < v.size(); ++i) {
//        for (int j = 1; j <= N; ++j) {
//            if (G[v[i]][j]) {
//                a[i].push_back(j);
//            }
//        }
//    }
//    vector<int> ans = a[0];
//    vector<int> tmp;
//    for (int i = 1; i < v.size(); ++i) {
//        set_intersection(ans.begin(), ans.end(), a[i].begin(), a[i].end(), back_inserter(tmp));
//        ans = tmp;
//        tmp.clear();
//    }
//    if (!ans.empty()) return 0;
//  Better way:
    for (int i = 1; i <= N; ++i) {
        int cnt = 0;
        if (flag[i]) continue;
        for (auto j: v) {
            if (G[j][i]) cnt++;
        }
        if (cnt == v.size())
            return 0;
    }
    return 1;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a][b] = true;
        G[b][a] = true;
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int num;
        cin >> num;
        if (num == 0) return 1;
        vector<int> tmp(num);
        for (int j = 0; j < num; j++) {
            cin >> tmp[j];
        }
        int ans = judge(tmp);
        if (ans == 0) {
            cout << "Not Maximal" << endl;
        }
        else if (ans == 1) {
            cout << "Yes" << endl;
        }
        else {
            cout << "Not a Clique" << endl;
        }
    }


    return 0;
}
