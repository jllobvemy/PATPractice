#include <bits/stdc++.h>
// Accepted!
using namespace std;
#define endl '\n'
constexpr int MAXLEN = 1010;
array<array<bool, MAXLEN>, MAXLEN> G;
array<bool, MAXLEN> visited;


int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a][b] = true;
        if (G[b][a]) return 1;
    }
    int K;
    cin >> K;
    bool first = true;
    for (int i = 0; i < K; ++i) {
        fill(visited.begin(), visited.end(), false);
        vector<int> path(N + 1);
        bool ans = true;
        for (int j = 1; j <= N; ++j) {
            cin >> path[j];
        }
        for (int j = 1; j <= N; ++j) {
            if (G[i][path[1]]) {
                ans = false;
                goto end;
            }
        }
        visited[path[1]] = true;
        for (int j = 2; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                if (G[k][path[j]] && !visited[k]) {
                    ans = false;
                    goto end;
                }
            }
            visited[path[j]] = true;
        }
        end:;
        if (!ans) {
            if (first) first = false;
            else cout << " ";
            cout << i;
        }
    }



    return 0;
}
