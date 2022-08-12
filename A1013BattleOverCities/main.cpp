#include <bits/stdc++.h>
// Accepted! BFS & DFS
using namespace std;
constexpr int MAXLEN = 1050;
int N, M, K;
array<array<bool, MAXLEN>, MAXLEN> Gtmp;
array<bool, MAXLEN> visited;

void BFS(int node) {
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        node = q.front();
        q.pop();
        for (int i = 1; i <= N; ++i) {
            if (Gtmp[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int BFSTraverse(int node) {
    fill(visited.begin(), visited.end(), false);
    int ret = 0;
    visited[node] = true;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            BFS(i);
            ret++;
        }
    }
    return ret - 1;
}

void DFS(int node) {
    for (int i = 1; i <= N; ++i) {
        if (Gtmp[node][i] && !visited[i]) {
            visited[i] = true;
            DFS(i);
        }
    }
}

int DFSTraverse(int node) {
    fill(visited.begin(), visited.end(), false);
    int ret = 0;
    visited[node] = true;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            DFS(i);
            ret++;
        }
    }
    return ret - 1;
}


int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= M; ++i) {
        int c1, c2;
        cin >> c1 >> c2;
        Gtmp[c1][c2] = true;
        Gtmp[c2][c1] = true;
    }
    for (int i = 0; i < K; ++i) {
        int q;
        cin >> q;
        int tmp = DFSTraverse(q);
//        int tmp = BFSTraverse(q);
        cout << tmp << endl;
    }
    return 0;
}
