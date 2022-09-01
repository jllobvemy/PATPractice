#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 10010;
vector<int> Adj[MAXLEN];
array<int, MAXLEN> color;


int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        set<int> colorset;
        for (int j = 0; j < N; ++j) {
            cin >> color[j];
            colorset.insert(color[j]);
        }
        bool flag = true;
        for (int j = 0; j < N; ++j) {
            for (auto e: Adj[j]) {
                if (color[j] == color[e])  {
                    flag = false;
                    goto end;
                }
            }
        }
        end:;
        if (flag) {
            cout << colorset.size() << "-coloring" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}
