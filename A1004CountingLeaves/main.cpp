#include <bits/stdc++.h>
// Accepted!
using namespace std;
int N, M;
struct Node {
    vector<int> children;
};
vector<Node> tree;
vector<int> ans;

int BFS(int root) {
    queue<int> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        level++;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            root = q.front();
            q.pop();
            if (tree[root].children.empty()) ans[level]++;
            else for (auto elem: tree[root].children) {
                q.push(elem);
            }
        }
    }
    return level;
}

int main() {
    cin >> N >> M;
    tree.resize(N + 1);
    ans.resize(N + 2, 0);
    for (int i = 0; i < M; ++i) {
        int ID;
        cin >> ID;
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int c;
            cin >> c;
            tree[ID].children.push_back(c);
        }
    }
    int level = BFS(1);
    bool first = true;
    for (int i = 1; i <= level; ++i) {
        if (first) {
            first = false;
            cout << ans[i];
        }
        else {
            cout << " " << ans[i];
        }
    }
    cout << endl;
    return 0;
}
