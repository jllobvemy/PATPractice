#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 10000;
struct Node {
    int left = -1;
    int right = -1;
    int parent = -1;
    int index = -1;
};
array<Node, MAXLEN> tree;
int lastLeaf = 0;

bool LevelTrev(int root) {
    queue<Node> q;
    q.push(tree[root]);
    while (!q.empty()) {
        int size = q.size();
        bool flag = true;
        while (size-- && flag) {
            auto top = q.front();
            if (size == 0) lastLeaf = top.index;
            q.pop();
            if (top.left != -1) q.push(tree[top.left]);
            if (top.right != -1) q.push(tree[top.right]);
            if (top.right != -1 && top.left == -1) return false;
            if (top.left != -1 && top.right == -1 || top.left == -1 && top.right == -1) {
                if (top.left != -1)
                    q.push(tree[top.left]);
                while (!q.empty()) {
                    top = q.front();
                    q.pop();
                    if (top.left != -1 || top.right != -1) return false;
                    else lastLeaf = top.index;
                    flag = false;
                }
            }
        }
    }
    return true;
}
int main() {
    int N;
    cin >> N;
    int root = -1;
    int maxLeaf = -1;
    for (int i = 0; i < N; ++i) {
        string l, r;
        cin >> l >> r;
        if (l[0] != '-') {
            int il = stoi(l);
            tree[il].parent = i;
            tree[il].index = il;
            tree[i].left = il;
            if (root == -1) root = il;
            if (il > maxLeaf) maxLeaf = il;
        }
        if (r[0] != '-') {
            int ir = stoi(r);
            tree[ir].parent = i;
            tree[ir].index = ir;
            tree[i].right = ir;
            if (root == -1) root = ir;
            if (ir > maxLeaf) maxLeaf = ir;
        }
    }
    while (tree[root].parent != -1) {
        root = tree[root].parent;
    }
    bool res = LevelTrev(root);
    if (res) {
        if (lastLeaf == -1) lastLeaf = 0;
        cout << "YES " << lastLeaf << endl;
    }
    else {
        cout << "NO " << root << endl;
    }
    return 0;
}
