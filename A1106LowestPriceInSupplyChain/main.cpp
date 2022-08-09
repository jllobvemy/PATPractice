#include <bits/stdc++.h>
using namespace std;
struct Node {
    vector<int> children;
    bool isLeaf = false;
};
vector<Node> tree;
int N;
double P, r;
int MinDepth = INT_MAX;
vector<int> DepthCount;

void DFS(int root, int depth) {
    if (tree[root].isLeaf) {
        DepthCount[depth]++;
        if (depth < MinDepth) {
            MinDepth = depth;
        }
    }
    for (auto i: tree[root].children) {
        DFS(i, depth + 1);
    }
}

void BFS(int root) {
    queue<int> q;
    q.push(root);
    MinDepth = 0;
    bool findLeaf = false;
    while (!q.empty()) {
        if (findLeaf) break;
        MinDepth++;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            root = q.front();
            q.pop();
            if (tree[root].isLeaf) {
                DepthCount[MinDepth]++;
                findLeaf = true;
            }
            if (findLeaf) continue;
            for (auto elem: tree[root].children) {
                q.push(elem);
            }
        }
    }
}


int main() {
    cin >> N >> P >> r;
    tree.resize(N);
    DepthCount.resize(N + 10, 0);
    r /= 100;
    for (int i = 0; i < N; ++i) {
        int sNum;
        cin >> sNum;
        if (sNum == 0) tree[i].isLeaf = true;
        else for (int j = 0; j < sNum; ++j) {
            int dis;
            cin >> dis;
            tree[i].children.push_back(dis);
        }
    }
//    DFS(0, 0);
//    printf("%.4f %d", P * pow((1 + r), MinDepth), DepthCount[MinDepth]);
    BFS(0);
    printf("%.4f %d", P * pow((1 + r), MinDepth - 1), DepthCount[MinDepth]);
    return 0;
}
