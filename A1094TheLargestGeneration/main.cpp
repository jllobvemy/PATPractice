#include <bits/stdc++.h>
// Accepted!
using namespace std;
int N, M;
struct Node {
    vector<int> children;
};
vector<Node> tree;
int ans = 0;
int ansLevel = 0;
void BFS(int root) {
    queue<int> nodes;
    nodes.push(root);
    int level = 0;
    while (!nodes.empty()) {
        int size = nodes.size();
        level++;
        if (size > ans) {
            ans = size;
            ansLevel = level;
        }
        while (size--) {
            root = nodes.front();
            nodes.pop();
            for (auto i: tree[root].children) {
                nodes.push(i);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    tree.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int cnode;
        cin >> cnode;
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int child;
            cin >> child;
            tree[cnode].children.push_back(child);
        }
    }
    BFS(1);
    cout << ans << " " << ansLevel;
    return 0;
}
