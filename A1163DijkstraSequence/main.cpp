#include <bits/stdc++.h>
// Accepted!
//#include <debug/vector>
using namespace std;
//#define vector __gnu_debug::vector
constexpr int MAXLEN = 1010, INF = INT_MAX / 2 - 1;
array<array<int, MAXLEN>, MAXLEN> G;
array<int, MAXLEN> d;
array<bool, MAXLEN> visited;
int Nv, Ne;

void Init() {
    for (int i = 0; i < MAXLEN; ++i) {
        for (int j = 0; j < MAXLEN; ++j) {
            G[i][j] = INF;
        }
    }
}

bool Dijkstra(vector<int>& vec) {
    fill(visited.begin(), visited.end(), false);
    fill(d.begin(), d.end(), INF + 1);
    d[vec[0]] = 0;
    for (int i = 1, vi = 0; i <= Nv; ++i, vi++) {
        int u = -1, minlen = INF;
        bool flag = false;
        for (int j = 1; j <= Nv; ++j) {
            if (!visited[j]) {
                if (d[j] < minlen) {
                    if (j == vec[vi]) flag = true;
                    u = j;
                    minlen = d[j];
                }
                if (d[j] == minlen && j == vec[vi]) {
                    flag = true;
                    u = j;
                }
            }
        }
        if (u == -1 || !flag) return false;
        visited[u] = true;
        for (int v = 1; v <= Nv; ++v) {
            if (!visited[v] && G[u][v] != INF) {
                if (G[u][v] + d[u] < d[v]) {
                    d[v] = G[u][v] + d[u];
                }
            }
        }
    }
    return true;
}

int main() {
    Init();
    cin >> Nv >> Ne;
    for (int i = 0; i < Ne; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a][b] = w;
        G[b][a] = w;
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        vector<int> vec(Nv);
        for (int j = 0; j < Nv; ++j) {
            cin >> vec[j];
        }
        bool res = Dijkstra(vec);
        cout << (res? "Yes": "No") << endl;
    }

}