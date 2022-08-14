#include <bits/stdc++.h>
// Not Complete.
constexpr int MAXLEN = 1050;
constexpr int INF = INT_MAX / 2 - 1;
using namespace std;
array<array<int, MAXLEN>, MAXLEN> G;
array<int, MAXLEN> d;
array<bool, MAXLEN> visited;
array<int, MAXLEN> pre;
int N, M, K, Ds;

void Init() {
    for (int i = 0; i < MAXLEN; ++i) {
        d[i] = INF;
        visited[i] = false;
        pre[i] = i;
        for (int j = 0; j < MAXLEN; ++j) {
            G[i][j] = INF;
        }
    }
}
void Reset() {
    for (int i = 0; i < MAXLEN; ++i) {
        d[i] = INF;
        visited[i] = false;
        pre[i] = i;
    }
}

void Dijkstra(int n) {
    Reset();
    d[n] = 0;
    for (int i = 1; i <= N + M; ++i) {
        int u = -1, minLen = INF;
        for (int j = 1; j <= N + M; ++j) {
            if (!visited[j] && d[j] < minLen) {
                u = j; minLen = d[j];
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (int v = 1; v <= N + M; ++v) {
            if (!visited[v] && G[u][v] != INF) {
                if (G[u][v] + d[u] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    pre[v] = u;
                }
            }
        }
    }
}

vector<int> PathTmp;
void DFS(int n) {
    if (pre[n] == n) {
        PathTmp.push_back(n);
        return;
    }
    PathTmp.push_back(n);
    DFS(pre[n]);
}

vector<int> GetPath(int n) {
    PathTmp.clear();
    DFS(n);
    std::reverse(PathTmp.begin(), PathTmp.end());
    return PathTmp;
}


int main() {
    Init();
    cin >> N >> M >> K >> Ds;
    for (int i = 0; i < K; ++i) {
        string s1, s2;
        int dis;
        int is1, is2;
        cin >> s1 >> s2 >> dis;
        if (s1[0] == 'G') {
            is1 = N + atoi(s1.c_str() + 1);
        }
        else is1 = atoi(s1.c_str());
        if (s2[0] == 'G') {
            is2 = N + atoi(s2.c_str() + 1);
        }
        else is2 = atoi(s2.c_str());
        G[is1][is2] = dis;
        G[is2][is1] = dis;
    }
    int maxSumDis = 0;
    map<int, int> minSumDis;
    map<int, int> minEachDis;
    set<int> ans0;
    for (int i = N + 1; i <= M + N; ++i) {
        int minDis = INF;
        int sum = 0;
        Dijkstra(i);
        for (int j = 1; j <= N + M; ++j) {
            if (minDis > d[j]) {
                minDis = d[j];
                minEachDis[i] = minDis;
            }
            sum += d[j];
        }
        minSumDis[i] = sum;
        if (maxSumDis < sum) {
            maxSumDis = sum;
            ans0.clear();
            ans0.insert(i);
        }
        else if (maxSumDis == sum) {
            ans0.insert(i);
        }
    }

    bool hasAnswer = false;
    for (auto& e: minEachDis) {
        if (e.second < Ds) {
            hasAnswer = true;
            break;
        }
    }
    if (!hasAnswer) {
        cout << "No Solution" << endl;
        return 0;
    }
    set<int> ans;
    int minDis = INF;
    if (ans0.size() > 1) {
        for (auto i: ans0) {
            if (minSumDis[i] < minDis) {
                minDis = minSumDis[i];
                ans.clear();
                ans.insert(i);
            }
            else if (minSumDis[i] == minDis) {
                ans.insert(i);
            }
        }
    }
    cout << "G" << *ans.begin() - N << endl;
    cout << minEachDis[*ans.begin()] << " " << minSumDis[*ans.begin()] * 1.0 / N << endl;
    return 0;
}
