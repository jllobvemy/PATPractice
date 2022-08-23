#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 1000;
constexpr int INF = INT_MAX / 2 - 1;
int N, M;
array<array<int, MAXLEN>, MAXLEN> GD;
array<array<int, MAXLEN>, MAXLEN> GT;
array<int, MAXLEN> d;
array<int, MAXLEN> t;
array<vector<int>, MAXLEN> PreD;
array<vector<int>, MAXLEN> PreT;
array<bool, MAXLEN> visited;
vector<int> tmpPath;
vector<vector<int>> DPaths;
void DFSD(int n) {
    if (PreD[n].empty()) {
        tmpPath.push_back(n);
        DPaths.push_back(tmpPath);
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(n);
    for (auto i: PreD[n]) {
        DFSD(i);
    }
    tmpPath.pop_back();
}
vector<vector<int>> TPaths;
void DFST(int n) {
    if (PreT[n].empty()) {
        tmpPath.push_back(n);
        TPaths.push_back(tmpPath);
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(n);
    for (auto i: PreT[n]) {
        DFST(i);
    }
    tmpPath.pop_back();
}
void Init() {
    for (int i = 0; i < MAXLEN; ++i) {
        for (int j = 0; j < MAXLEN; ++j) {
            GD[i][j] = GT[i][j] = INF;
        }
    }
}

void DDijkstra(int n) {
    fill(visited.begin(), visited.end(), false);
    fill(d.begin(), d.end(), INF);
    d[n] = 0;
    for (int i = 0; i < N; ++i) {
        int u = -1, maxlen = INF;
        for (int j = 0; j < N; ++j) {
            if (d[j] != INF && d[j] < maxlen && !visited[j]) {
                u = j;
                maxlen = d[j];
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (int v = 0; v < N; ++v) {
            if (GD[u][v] != INF && !visited[v]) {
                if (GD[u][v] + d[u] < d[v]) {
                    PreD[v].clear();
                    PreD[v].push_back(u);
                    d[v] = GD[u][v] + d[u];
                }
                else if (GD[u][v] + d[u] == d[v]) {
                    PreD[v].push_back(u);
                }
            }
        }
    }
}
void TDijkstra(int n) {
    fill(visited.begin(), visited.end(), false);
    fill(t.begin(), t.end(), INF);
    t[n] = 0;
    for (int i = 0; i < N; ++i) {
        int u = -1, maxlen = INF;
        for (int j = 0; j < N; ++j) {
            if (t[j] != INF && t[j] < maxlen && !visited[j]) {
                u = j;
                maxlen = t[j];
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (int v = 0; v < N; ++v) {
            if (GT[u][v] != INF && !visited[v]) {
                if (GT[u][v] + t[u] < t[v]) {
                    PreT[v].clear();
                    PreT[v].push_back(u);
                    t[v] = GT[u][v] + t[u];
                }
                else if (GT[u][v] + t[u] == t[v]) {
                    PreT[v].push_back(u);
                }
            }
        }
    }

}

int main() {
    Init();
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, oneway, dis, time;
        cin >> a >> b >> oneway >> dis >> time;
        GD[a][b] = dis;
        GT[a][b] = time;
        if (oneway != 1) {
            GD[b][a] = dis;
            GT[b][a] = time;
        }
    }
    int start, end;
    cin >> start >> end;
    DDijkstra(start);
    TDijkstra(start);
    DFSD(end);
    DFST(end);
    int fast = INF;
    vector<int> ansD;
    for (auto& p: DPaths) {
        std::reverse(p.begin(), p.end());
        int time = 0;
        for (int i = 1; i < p.size(); ++i) {
            time += GT[p[i - 1]][p[i]];
        }
        if (time < fast) {
            ansD = p;
            fast = time;
        }
    }
    vector<int> ansT;
    int minlen = INF;
    for (auto& p: TPaths) {
        std::reverse(p.begin(), p.end());
        if (p.size() < minlen) {
            ansT = p;
            minlen = p.size();
        }
    }
    if (ansT != ansD) {
        cout << "Distance = " << d[end] << ": ";
        bool first = true;
        for (auto i: ansD) {
            if (first) {
                cout << i;
                first = false;
            }
            else cout << " -> " << i;
        }
        cout << endl;
        cout << "Time = " << t[end] << ": ";
        first = true;
        for (auto i: ansT) {
            if (first) {
                cout << i;
                first = false;
            }
            else cout << " -> " << i;
        }
        cout << endl;
    }
    else {
        char buf[50];
        sprintf(buf, "Distance = %d; Time = %d: ", d[end], t[end]);
        cout << buf;
        bool first = true;
        for (auto i: ansD) {
            if (first) {
                cout << i;
                first = false;
            }
            else cout << " -> " << i;
        }
    }

    return 0;
}
