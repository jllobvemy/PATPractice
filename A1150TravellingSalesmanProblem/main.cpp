#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 210;
constexpr int INF = INT_MAX / 2 - 1;
array<array<int, MAXLEN>, MAXLEN> G;
void Init() {
    for (int i = 0; i < MAXLEN; ++i) {
        for (int j = 0; j < MAXLEN; ++j) {
            G[i][j] = INF;
        }
    }
}
int N, M;
struct Ans {
    int ans;
    int len;
};
array<bool, MAXLEN> visited;
Ans judge(vector<int>& vec) {
    fill(visited.begin(), visited.end(), false);
    bool isSimple = true;
    int len = 0;
    visited[vec[0]] = true;
    for (int i = 1; i < vec.size(); ++i) {
        int pathlen = G[vec[i - 1]][vec[i]];
        if (pathlen == INF) {
            return{3, INF};
        }
        if (visited[vec[i]] && i != vec.size() - 1) {
            isSimple = false;
        }
        visited[vec[i]] = true;
        len += pathlen;
    }
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            return {3, len};
        }
    }
    if (vec.front() == vec.back()) {
        if (isSimple) {
            return {1, len};
        }
        else {
            return {2, len};
        }
    }
    else {
        return {3, len};
    }
}

int main() {
    Init();
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a][b] = w;
        G[b][a] = w;
    }
    int K;
    cin >> K;
    char buf[100];
    int Min = INF;
    int MinIndex = -1;
    for (int i = 0; i < K; ++i) {
        int num;
        cin >> num;
        vector<int> path(num);
        for (int j = 0; j < num; ++j) {
            cin >> path[j];
        }
        auto ans = judge(path);
        string s;
        if (ans.ans == 1) {
            s = "TS simple cycle";
        }
        else if (ans.ans == 2) {
            s = "TS cycle";
        }
        else if (ans.ans == 3) {
            s = "Not a TS cycle";
        }
        if (ans.len < Min && ans.ans != 3) {
            Min = ans.len;
            MinIndex = i + 1;
        }
        if (ans.len != INF)
            sprintf(buf, "Path %d: %d (%s)\n", i + 1, ans.len, s.c_str());
        else
            sprintf(buf, "Path %d: NA (%s)\n", i + 1, s.c_str());
        cout << buf;
    }
    sprintf(buf, "Shortest Dist(%d) = %d\n", MinIndex, Min);
    cout << buf;
    return 0;
}
