#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 1050;
constexpr int INF = INT_MAX / 2 - 1;
int N, M, K, Ds;
array<array<int, MAXLEN>, MAXLEN> G;
array<bool, MAXLEN> visited;
array<vector<int>, MAXLEN> Pre;
array<int, MAXLEN> d;
void Init() {
    for (int i = 0; i < MAXLEN; ++i) {
        visited[i] = false;
        d[i] = INF;
        for (int j = 0; j < MAXLEN; ++j) {
            G[i][j] = INF;
        }
    }
}
void Reset() {
    for (int i = 0; i < MAXLEN; ++i) {
        visited[i] = false;
        d[i] = INF;
        Pre[i].clear();
    }
}

void Dijkstra(int n) {
    Reset();
    d[n] = 0;
    int TotalLocation = N + M + 10;
    for (int i = 0; i < TotalLocation; ++i) {
        int u = -1, minDis = INF;
        for (int j = 1; j <= TotalLocation; ++j) {
            if (!visited[j] && d[j] != INF && d[j] < minDis) {
                minDis = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (int v = 1; v <= TotalLocation; ++v) {
            if (!visited[v] && G[u][v] != INF) {
                if (G[u][v] + d[u] < d[v]) {
                    d[v] = G[u][v] + d[u];
                    Pre[v].clear();
                    Pre[v].push_back(u);
                }
                else if (G[u][v] + d[u] == d[v]) {
                    Pre[v].push_back(u);
                }
            }
        }
    }
}


int main() {
    Init();
    cin >> N >> M >> K >> Ds;
    string s1, s2;
    int dis;
    for (int i = 0; i < K; ++i) {
        cin >> s1 >> s2 >> dis;
        int p1, p2;
        if (s1[0] != 'G') {
            p1 = stoi(s1) + 10;
        }
        else {
            p1 = stoi(s1.substr(1, s1.length() - 1));
        }
        if (s2[0] != 'G') {
            p2 = stoi(s2) + 10;
        }
        else {
            p2 = stoi(s2.substr(1, s2.length() - 1));
        }
        G[p1][p2] = dis;
        G[p2][p1] = dis;
    }
    int minDis = -1;
    double minAveDis;
    int selectGas;
    for (int i = 1; i <= M; ++i) {
        Dijkstra(i);
        auto mm = minmax_element(d.begin() + 11, d.begin() + N + 11);
        if (*mm.second > Ds) continue;
        if (*mm.first > minDis) {
            selectGas = i;
            minDis = *mm.first;
            minAveDis = accumulate(d.begin() + 11, d.begin() + N + 11, 0) * 1.0 / N;
        }
        else if (*mm.first == minDis) {
            double tmpAve = accumulate(d.begin() + 11, d.begin() + N + 11, 0) * 1.0 / N;
            if (tmpAve < minAveDis) {
                minAveDis = tmpAve;
                selectGas = i;
            }
        }
    }
    char buf[50];
    if (minDis == -1) {
        sprintf(buf, "No Solution");
    }
    else {
        int tmp = round(minAveDis * 10);
        sprintf(buf, "G%d\n%.1f %.1f", selectGas, minDis * 1.0, tmp * 1.0 / 10);
    }
    cout << buf;
    return 0;
}