#include <bits/stdc++.h>
// Not ac. 25/30
constexpr int MAXLEN = 550;
constexpr int INF = INT_MAX / 2 - 1;
using namespace std;
array<int, MAXLEN> PointWeight;
array<int, MAXLEN> d;
array<bool, MAXLEN> visited;
array<array<int, MAXLEN>, MAXLEN> G;
int Cmax, N, Sp, M;

void Init() {
    for (int i = 0; i < MAXLEN; ++i) {
        d[i] = INF;
        for (int j = 0; j < MAXLEN; ++j) {
            G[i][j] = INF;
        }
    }
}

vector<int> pre[MAXLEN];
void Dijkstra(int n) {
    d[n] = 0;
    for (int i = 0; i <= N; ++i) {
        int u = -1, mind = INF;
        for (int j = 0; j <= N; ++j) {
            if (!visited[j] && d[j] < mind) {
                u = j;
                mind = d[j];
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (int v = 0; v <= N; ++v) {
            if (!visited[v] && G[u][v] != INF) {
                if (G[u][v] + d[u] < d[v]) {
                    d[v] = G[u][v] + d[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (G[u][v] + d[u] == d[v]) {
                    pre[v].push_back(u);
                }

            }
        }
    }
}

vector<vector<int>> sPath;
vector<int> tmp;

void DFS(int n) {
    if (pre[n].empty()) {
        tmp.push_back(n);
        sPath.push_back(tmp);
        tmp.pop_back();
    }
    tmp.push_back(n);
    for (auto e: pre[n]) {
        DFS(e);
    }
    tmp.pop_back();
}

int main() {
    cin >> Cmax >> N >> Sp >> M;
    Init();
    for (int i = 1; i <= N; ++i) {
        int tmp;
        cin >> tmp;
        PointWeight[i] = tmp;
    }
    for (int i = 0; i < M; ++i) {
        int s1, s2, w;
        cin >> s1 >> s2 >> w;
        G[s1][s2] = w;
        G[s2][s1] = w;
    }
    int perfectNum = Cmax / 2;
    Dijkstra(0);
    DFS(Sp);
    vector<int> path;
    int minLake = INF;
    int minRet = INF;
    for (const auto& e: sPath) {
        int minLakeTmp = 0;
        int retBike = 0;
        for (auto it = e.rbegin() + 1; it != e.rend(); it++) {
            int lake = perfectNum - PointWeight[*it];
            retBike += lake;
            minLakeTmp = max(minLakeTmp, retBike);
        }
        if (retBike > 0) retBike = 0; // retBike < 0 表示返回abs(retBike)数量的车
        else retBike = -retBike;
        if (minLake > minLakeTmp) {
            minLake = minLakeTmp;
            path = e;
            minRet = retBike;
        }
        else if (minLakeTmp == minLake) {
            if (retBike < minRet) {
                minRet = retBike;
                path = e;
            }
        }
    }
    cout << minLake << " ";
    bool first = true;
    for (auto it = path.rbegin(); it != path.rend(); it++) {
        if (first) {
            cout << *it; first = false;
        }
        else {
            cout << "->" << *it;
        }
    }
    cout << " " << minRet;
    return 0;
}
