#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct Node{
    vector<int> children;
    bool isLeaf = false;
    int data = 0;
};
vector<Node> tree;
int N;
double P, r;
long double ans = 0.0;

void DFS(int root, double currentPrice) {
    if (tree[root].isLeaf) {
        ans += currentPrice * tree[root].data;
        return;
    }
    for (auto c: tree[root].children) {
        DFS(c, currentPrice * (1 + r));
    }
}

int main() {
    cin >> N >> P >> r;
    r /= 100;
    tree.resize(N);
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        int tmp;
        if (num == 0) {
            cin >> tmp;
            tree[i].isLeaf = true;
            tree[i].data = tmp;
        }
        for (int j = 0; j < num; ++j) {
            cin >> tmp;
            tree[i].children.push_back(tmp);
        }
    }
    DFS(0, P);
    char tmp[500];
    sprintf(tmp, "%.1Lf", ans);
    cout << tmp;
    return 0;
}
