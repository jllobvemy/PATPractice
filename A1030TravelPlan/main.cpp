#include <bits/stdc++.h>
// Accepted!
constexpr int MAXLEN = 550;
constexpr int INF = INT_MAX / 2 - 1;
using namespace std;
int N, M, S, D;
array<array<int, MAXLEN>, MAXLEN> G;
array<array<int, MAXLEN>, MAXLEN> CostG;
array<bool, MAXLEN> visited;
array<int, MAXLEN> d;
vector<int> PreVec[MAXLEN];

void Dijkstra(int s) {
    d[s] = 0;
    for (int i = 0; i < N; ++i) {
        int u = -1, mind = INF;
        for (int j = 0; j < N; ++j) {
            if (!visited[j] && d[j] < mind) {
                u = j;
                mind = d[j];
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (int v = 0; v < N; ++v) {
            if (!visited[v] && G[u][v] != INF) {
                if (G[u][v] + d[u] < d[v]) {
                    d[v] = G[u][v] + d[u];
                    PreVec[v].clear();
                    PreVec[v].push_back(u);
                }
                else if (G[u][v] + d[u] == d[v]) {
                    PreVec[v].push_back(u);
                }
            }
        }
    }
}
int minCost = INF;
int curtCost = 0;
vector<int> ansPathVec;
vector<int> tmpPathVec;

void DFS(int node) {
    if (PreVec[node].empty()) {
        tmpPathVec.push_back(node);
        if (curtCost < minCost) {
            ansPathVec = tmpPathVec;
            minCost = curtCost;
        }
        tmpPathVec.pop_back();
    }
    tmpPathVec.push_back(node);
    for (auto i: PreVec[node]) {
        curtCost += CostG[node][i];
        DFS(i);
        curtCost -= CostG[node][i];
    }
    tmpPathVec.pop_back();
}

void Init() {
    for (int i = 0; i < MAXLEN; ++i) {
        d[i] = INF;
        for (int j = 0; j < MAXLEN; ++j) {
            G[i][j] = INF;
            CostG[i][j] = INF;
        }
    }
}


int main() {
    cin >> N >> M >> S >> D;
    Init();
    for (int i = 0; i < M; ++i) {
        int C1, C2, Dis, Cost;
        cin >> C1 >> C2 >> Dis >> Cost;
        G[C1][C2] = Dis;
        G[C2][C1] = Dis;
        CostG[C1][C2] = Cost;
        CostG[C2][C1] = Cost;
    }
    Dijkstra(S);
    DFS(D);
    bool first = true;
    for (auto it = ansPathVec.rbegin(); it != ansPathVec.rend(); it++) {
        if (first) {
            cout << *it;
            first = false;
        }
        else cout << " " << *it;
    }
    cout << " " << d[D];
    cout << " " << minCost;
    return 0;
}
