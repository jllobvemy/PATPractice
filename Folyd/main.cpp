#include <bits/stdc++.h>
using namespace std;
constexpr int MAXLEN = 200;
constexpr int INF = INT_MAX / 2 - 1;
array<array<int, MAXLEN>, MAXLEN> dis;
int M, N;

void Init() {
    for (int i = 0; i < MAXLEN; i++) {
        for (int j = 0; j < MAXLEN; ++j) {
            dis[i][j] = INF;
        }
    }
    for (int i = 0; i < MAXLEN; ++i) {
        dis[i][i] = 0;
    }
}

void Folyd() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                if (dis[i][j] + dis[j][k] < dis[i][k]) {
                    dis[i][k] = dis[i][j] + dis[j][k];
                }
            }
        }
    }
}

array<array<int, MAXLEN>, MAXLEN> G;
array<bool, MAXLEN> vis;
array<int, MAXLEN> d;

int Prim() {
    fill(vis.begin(), vis.end(), false);
    fill(d.begin(), d.end(), INF);
    d[0] = 0;
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        int u = -1, minlen = INF;
        for (int j = 0; j < N; ++j) {
            if (!vis[j] && d[j] < minlen) {
                u = j;
                minlen = d[j];
            }
        }
        if (u == -1) return ret;
        ret += d[u];
        vis[u] = true;
        for (int v = 0; v < N; ++v) {
            if (!vis[v] && G[u][v] != INF && G[u][v] < d[v]) {
                d[v] = G[u][v];
            }
        }
    }
    return ret;
}

int main() {
    Init();
    freopen("../input.txt", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        dis[a][b] = w;
        dis[b][a] = w;
    }
    Folyd();
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        cout << dis[a][b] << endl;
    }



    return 0;
}
