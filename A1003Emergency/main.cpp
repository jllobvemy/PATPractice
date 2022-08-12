#include <bits/stdc++.h>
// Accepted! 邻接表
constexpr int MAXLEN = 600;
constexpr int INF = INT_MAX / 2 - 1;
using namespace std;
int N, M, C1, C2;
struct Node {
    int index;
    int weight;
    Node(int i, int w): index(i), weight(w) {}
};
array<int, MAXLEN> CWeight;
array<bool, MAXLEN> visited;
array<int, MAXLEN> preLen;
array<int, MAXLEN> rescueTeam;
array<int, MAXLEN> d;
vector<Node> Adj[MAXLEN];

void init() {
    for (int i = 0; i < MAXLEN; ++i) {
        d[i] = INF;
    }
}

void Dijkstra(int s) {
    d[s] = 0;
    rescueTeam[s] = CWeight[s];
    preLen[s] = 1;
    for (int i = 0; i < N; ++i) {
        int u = -1, minlen = INF;
        for (int j = 0; j < N; ++j) {
            if (d[j] < minlen && !visited[j]) {
                u = j;
                minlen = d[j];
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (auto& j: Adj[u]) {
            int v = j.index;
            if (!visited[v]) {
                if(j.weight + d[u] < d[v]) {
                    d[v] = j.weight + d[u];
                    preLen[v] = preLen[u];
                    rescueTeam[v] = rescueTeam[u] + CWeight[v];
                }
                else if (j.weight + d[u] == d[v]) {
                    preLen[v] += preLen[u];
                    if (rescueTeam[u] + CWeight[v] > rescueTeam[v]) {
                        rescueTeam[v] = rescueTeam[u] + CWeight[v];
                    }
                }
            }
        }
    }
}



int main() {
    cin >> N >> M >> C1 >> C2;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        CWeight[i] = tmp;
    }
    for (int i = 0; i < M; ++i) {
        int c1, c2, l;
        cin >> c1 >> c2 >> l;
        Adj[c1].emplace_back(c2, l);
        Adj[c2].emplace_back(c1, l);
    }
    init();
    Dijkstra(C1);
    cout << preLen[C2] << " " << rescueTeam[C2] << endl;
    return 0;
}
