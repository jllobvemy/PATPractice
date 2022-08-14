#include <bits/stdc++.h>
// Accepted!
constexpr int MAXLEN = 1050;
constexpr int INF = INT_MAX / 2 - 1;
using namespace std;
int N, K;
string Start;
map<int, string> index2name;
map<string, int> name2index;
int CurtIndex = 0;
int GetIndex(const string& name) {
    if (name2index.find(name) == name2index.end()) {
        name2index[name] = CurtIndex;
        index2name[CurtIndex] = name;
        CurtIndex++;
    }
    return name2index[name];
}
const string& GetName(int index) {
    if (index2name.find(index) == index2name.end()) {
        exit(3);
    }
    return index2name[index];
}
array<bool, MAXLEN> visited;
array<int, MAXLEN> d;
array<int, MAXLEN> w;
array<array<int, MAXLEN>, MAXLEN> G;

void Init() {
    for (int i = 0; i < MAXLEN; ++i) {
        d[i] = INF;
        for (int j = 0; j < MAXLEN; ++j) {
            G[i][j] = INF;
        }
    }
}

vector<int> pre[MAXLEN];
void Dijkstra(int node) {
    d[node] = 0;
    for (int i = 0; i < N; ++i) {
        int u = -1, maxLen = INF;
        for (int j = 0; j < N; ++j) {
            if (!visited[j] && d[j] < maxLen) {
                maxLen = d[j];
                u = j;
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (int v = 0; v < N; ++v) {
            if (!visited[v] && G[u][v] != INF) {
                if (G[u][v] + d[u] < d[v]) {
                    pre[v].clear();
                    pre[v].push_back(u);
                    d[v] = G[u][v] + d[u];
                }
                else if (G[u][v] + d[u] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

vector<vector<int>> Paths;
vector<int> PathTmp;
void DFS(int node) {
    if (pre[node].empty())  {
        PathTmp.push_back(node);
        Paths.push_back(PathTmp);
        PathTmp.pop_back();
        return;
    }
    PathTmp.push_back(node);
    for (auto i: pre[node]) {
        DFS(i);
    }
    PathTmp.pop_back();
}

const vector<vector<int>>& GetPaths(int end) {
    DFS(end);
    for (auto& v: Paths) {
        std::reverse(v.begin(), v.end());
    }
    return Paths;
}


int main() {
    Init();
    cin >> N >> K >> Start;
    for (int i = 0; i < N - 1; ++i) {
        string s;
        int weight;
        cin >> s >> weight;
        w[GetIndex(s)] = weight;
    }
    w[GetIndex(Start)] = 0;
    for (int i = 0; i < K; ++i) {
        string s1, s2;
        int weight;
        cin >> s1 >> s2 >> weight;
        int i1 = GetIndex(s1), i2 = GetIndex(s2);
        G[i1][i2] = weight;
        G[i2][i1] = weight;
    }
    Dijkstra(GetIndex(Start));
    const auto& path = GetPaths(GetIndex("ROM"));
    int maxHappiness = -1, maxAveHappiness = -1;
    vector<int> ansPath;
    for (auto& v: path) {
        int happiness = 0, aveHappiness = 0;
        for (auto i: v) {
            happiness += w[i];
        }
        aveHappiness = happiness * 1.0 / (v.size() - 1);
        if (happiness > maxHappiness) {
            ansPath = v;
            maxAveHappiness = aveHappiness;
            maxHappiness = happiness;
        }
        else if (happiness == maxHappiness) {
            if (aveHappiness > maxAveHappiness) {
                maxAveHappiness = aveHappiness;
                ansPath = v;
            }
        }
    }
    cout << path.size() << " " << d[GetIndex("ROM")] << " " << maxHappiness << " " << maxAveHappiness << endl;
    bool first = true;
    for (auto p: ansPath) {
        if (first) {
            first = false;
            cout << GetName(p);
        }
        else {
            cout << "->" << GetName(p);
        }
    }
    return 0;
}
