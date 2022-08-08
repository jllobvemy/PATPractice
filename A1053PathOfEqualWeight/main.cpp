#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct Node {
    int weight;
    vector<int> children;
};
int N, M, S;
vector<Node> tree;
vector<int> tmpans;
int tmpsum = 0;
vector<vector<int>> ans;

void DFS(int root) {
    if (root >= N || root < 0) return;
    if (tmpsum > S) {
        return;
    } else if (tmpsum == S && tree[root].children.empty()) {
        ans.push_back(tmpans);
        return;
    }
    else
        for (auto i: tree[root].children) {
            tmpans.push_back(tree[i].weight);
            tmpsum += tree[i].weight;
            DFS(i);
            tmpans.pop_back();
            tmpsum -= tree[i].weight;
        }
}
bool cmp(const vector<int>& a, const vector<int>& b) {
    int num = min(a.size(), b.size());
    for (int i = 0; i < num; ++i) {
        if (a[i] > b[i])
            return true;
        if (a[i] < b[i])
            return false;
    }
    return false;  // 此处不能为true， 否则测试点5段错误，原因未知
}


int main() {
    cin >> N >> M >> S;
    tree.resize(N);
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        tree[i].weight = tmp;
    }
    for (int i = 0; i < M; ++i) {
        int ID;
        cin >> ID;
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int child;
            cin >> child;
            tree[ID].children.push_back(child);
        }
    }
    tmpans.push_back(tree[0].weight);
    tmpsum += tree[0].weight;
    DFS(0);
    if (ans.empty()) return 1;
    sort(ans.begin(), ans.end(), cmp);
    for (auto & an : ans) {
        bool first = true;
        for (auto elem: an) {
            if (first) {
                first = false;
                cout << elem;
            }
            else {
                cout << " " << elem;
            }
        }
        cout << endl;
    }
    return 0;
}
