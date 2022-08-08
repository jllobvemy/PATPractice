#include <bits/stdc++.h>
// Accepted!
using namespace std;
int N, M;
struct Node {
    vector<int> children;
};
vector<Node> tree;
vector<int> ans;
int maxDepth = 0;
void DFS(int root, int depth) {
    ans[depth]++;
    if (depth > maxDepth) maxDepth = depth;
    for (auto i: tree[root].children) {
        DFS(i, depth + 1);
    }
}

int main() {
    cin >> N >> M;
    tree.resize(N + 1);
    ans.resize(N + 1);
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
    DFS(1, 0);
    auto m = max_element(ans.begin(), ans.begin() + maxDepth + 2);
    cout << *m << " " << m - ans.begin() + 1;
    return 0;
}
