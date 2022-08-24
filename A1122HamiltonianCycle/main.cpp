#include <bits/stdc++.h>
// Accepted!
constexpr int MAXLEN = 250;
constexpr int INF = INT_MAX / 2 - 1;
using namespace std;
array<array<bool, MAXLEN>, MAXLEN> G;
array<bool, MAXLEN> visited;
int N, M;

bool isHamilton(vector<int>& a) {
    if (a.size() != N + 1 || *a.begin() != *(a.end() - 1)) return false;
    fill(visited.begin(), visited.end(), false);
    for (int i = 1; i < a.size(); ++i) {
        if (!visited[a[i]] && G[a[i]][a[i - 1]])
            visited[a[i]] = true;
        else return false;
    }
    return true;
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
        vector<int> tmp(num);
        for (int j = 0; j < num; ++j) {
            cin >> tmp[j];
        }
        if (isHamilton(tmp)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
