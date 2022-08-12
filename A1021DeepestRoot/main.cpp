#include <bits/stdc++.h>
// Accepted! BFS + 并查集
using namespace std;
constexpr int MAXLEN = 10050;
int N;
vector<int> Adj[MAXLEN];
array<int, MAXLEN> visited;
int maxLevel = 0;
vector<int> ans;

int BFS(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        level++;
        while (size--) {
            node = q.front();
            q.pop();
            for (auto i: Adj[node])  {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    return level;
}

void BFSTraverse() {
    for (int i = 1; i <= N; ++i) {
        fill(visited.begin(), visited.end(), false);
        int level = BFS(i);
        if (level > maxLevel) {
            ans.clear();
            ans.push_back(i);
            maxLevel = level;
        }
        else if (level == maxLevel) {
            ans.push_back(i);
        }
    }
}

array<int, MAXLEN> father;
int findFather(int n) {
    if (father[n] == n) {
        return n;
    }
    father[n] = findFather(father[n]);
    return father[n];
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa != fb) {
        father[fb] = fa;
    }
}

void initFather() {
    for (int i = 0; i < MAXLEN; ++i) {
        father[i] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    initFather();
    for (int i = 0; i < N - 1; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        Union(n1, n2);
        Adj[n1].push_back(n2);
        Adj[n2].push_back(n1);
    }
    int blockNum = 0;
    for (int i = 1; i <= N; ++i) {
        if (father[i] == i) {
            blockNum++;
        }
    }
    if (blockNum > 1) {
        char tmp[50];
        sprintf(tmp, "Error: %d components\n", blockNum);
        cout << tmp;
        return 0;
    }
    BFSTraverse();
    for (auto i: ans) {
        cout << i << '\n';
    }
    return 0;
}
