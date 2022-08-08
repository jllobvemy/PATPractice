#include <bits/stdc++.h>
using namespace std;
struct Node {
    vector<int> children;
};
vector<Node> tree;
int maxDepth = 0;
int ans = 0;
int N;
double P, r;

void DFS(int root, int depth) {
    if (maxDepth < depth) {
        maxDepth = depth;
        ans = 1;
    }
    else if (maxDepth == depth) {
        ans++;
    }
    for (auto e: tree[root].children) {
        DFS(e, depth + 1);
    }
}

int main() {
    int root;
    cin >> N >> P >> r;
    tree.resize(N);
    r /= 100;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp != -1) {
            tree[tmp].children.push_back(i);
        }
        else {
            root = i;
        }
    }
    DFS(root, 0);
    printf("%.2lf %d", pow(1 + r, maxDepth) * P, ans);
    return 0;
}
