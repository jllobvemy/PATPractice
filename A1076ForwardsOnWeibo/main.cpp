#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 1050;
array<array<bool, MAXLEN>, MAXLEN> G;
array<bool, MAXLEN> visited;
int N, L;

int BFS(int node) {
    int level = 0;
    if (visited[node]) return 0;
    int ret = 0;
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while (!q.empty()) {
        int size = q.size();
        level++;
        if (level > L) break;
        while (size--) {
            node = q.front();
            q.pop();
            for (int i = 1; i <= N; ++i) {
                if (G[node][i] && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                    ret++;
                }
            }
        }
    }
    return ret;
}


int main() {
    cin >> N >> L;
    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        for (int j = 1; j <= num; ++j) {
            int tmp;
            cin >> tmp;
            G[tmp][i] = true;
        }
    }
    int qnum;
    cin >> qnum;
    for (int i = 0; i < qnum; ++i) {
        int tmp;
        cin >> tmp;
        cout << BFS(tmp) << endl;
        fill(visited.begin(), visited.end(), false);
    }


    return 0;
}
