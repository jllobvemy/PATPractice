#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 1000;
struct Node {
    int left = -1;
    int right = -1;
    int parent = -1;
    string data;
};
array<Node, MAXLEN> tree;

stringstream ss;
void PostOrder(int n) {
    if (n == -1) return;
    ss << "(";
    if (tree[n].left != -1 && tree[n].right != -1) {
        PostOrder(tree[n].left);
        PostOrder(tree[n].right);
        ss << tree[n].data;
    }
    else {
        ss << tree[n].data;
        PostOrder(tree[n].left);
        PostOrder(tree[n].right);
    }
    ss << ")";
}
int findRoot(int n) {
    while (tree[n].parent != -1) {
        n = tree[n].parent;
    }
    return n;
}

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int a, b;
        cin >> tree[i].data;
        cin >> a >> b;
        if (a != -1) {
            tree[i].left = a;
            tree[a].parent = i;
        }
        if (b != -1) {
            tree[i].right = b;
            tree[b].parent = i;
        }
    }
    int root = findRoot(1);
    PostOrder(root);
    cout << ss.str();

    return 0;
}
