#include <bits/stdc++.h>
// Accepted! DFS
using namespace std;
constexpr int MAXLEN = 50000;
int N;
vector<int> tmp;
set<int> ans;
vector<int> Adj[MAXLEN];
array<bool, MAXLEN> visited;
int maxLevel = 0;

void DFS(int node, int level) {
    if (level > maxLevel) {
        tmp.clear();
        tmp.push_back(node);
        maxLevel = level;
    }
    else if (level == maxLevel) {
        tmp.push_back(node);
    }
    for (auto e: Adj[node]) {
        if (!visited[e]) {
            visited[e] = true;
            DFS(e, level + 1);
        }
    }
}


int main() {
    cin >> N;
    for (int i = 1; i <= N - 1; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        Adj[n1].push_back(n2);
        Adj[n2].push_back(n1);
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            cnt++;
            visited[i] = true;
            DFS(i, 1);
        }
    }
    if (cnt > 1) {
        char tmpstr[50];
        sprintf(tmpstr, "Error: %d components\n", cnt);
        cout << tmpstr;
        return 0;
    }
    for (auto i: tmp) {
        ans.insert(i);
    }
    fill(visited.begin(), visited.end(), false);
    DFS(tmp.front(), 1);
    for (auto i: tmp) {
        ans.insert(i);
    }
    for (auto i: ans) {
        cout << i << '\n';
    }
};
