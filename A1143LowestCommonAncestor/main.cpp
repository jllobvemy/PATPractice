#include <bits/stdc++.h>
// Not ac.
using namespace std;
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    int data;
};

vector<int> PreOrder;
vector<int> InOrder;

Node* Create(Node* parent, int PreLeft, int PreRight, int InLeft, int InRight) {
    if (PreLeft > PreRight) return nullptr;
    Node* ret = new Node;
    ret->data = PreOrder[PreLeft];
    ret->parent = parent;
    if (PreLeft == PreRight) return ret;
    int cnt = 0;
    while (PreOrder[PreLeft] != InOrder[InLeft + cnt]) cnt++;
    ret->left = Create(ret, PreLeft + 1, PreLeft + cnt, InLeft, InLeft + cnt - 1);
    ret->right = Create(ret, PreLeft + cnt + 1, PreRight, InLeft + cnt + 1, InRight);
    return ret;
}
map<int, int> value2level;
map<int, Node*> value2node;

void LevelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        level++;
        while (size--) {
            Node* tmp = q.front();
            q.pop();
            value2level[tmp->data] = level;
            value2node[tmp->data] = tmp;
            if (tmp->left) q.push(tmp->left);
            if (tmp->right) q.push(tmp->right);
        }
    }
}

int findCommonAncestor(int a, int b) {
    Node* na = value2node[a];
    Node* nb = value2node[b];
    vector<int> va;
    vector<int> vb;
    while (na) {
        va.push_back(na->data);
        na = na->parent;
    }
    while (nb) {
        vb.push_back(nb->data);
        nb = nb->parent;
    }
    int i = 0;
    while (va[va.size() - i - 1] == vb[vb.size() - i - 1]) {
        i++;
    }
    return va[va.size() - i];
}


int main() {
    int N, M;
    cin >> M >> N;
    Node *root = nullptr;
    PreOrder.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> PreOrder[i];
    }
    InOrder = PreOrder;
    sort(InOrder.begin(), InOrder.end());
    root = Create(nullptr, 0, N - 1, 0, N - 1);
    LevelOrder(root);
    char buf[100];
    for (int i = 0; i < M; ++i) {
        vector<int> a(2);
        cin >> a[0] >> a[1];
        auto f0 = value2level.find(a[0]), f1 = value2level.find(a[1]);
        if (f0 == value2level.end() && f1 != value2level.end()) {
            sprintf(buf, "ERROR: %d is not found.", a[0]);
        }
        if (f0 != value2level.end() && f1 == value2level.end()) {
            sprintf(buf, "ERROR: %d is not found.", a[1]);
        }
        if (f0 == value2level.end() && f1 == value2level.end()) {
            sprintf(buf, "ERROR: %d and %d are not found.", a[0], a[1]);
        }
        if (f0 != value2level.end() && f1 != value2level.end()) {
            int anc = findCommonAncestor(a[0], a[1]);
            if (anc == a[0]) {
                sprintf(buf, "%d is an ancestor of %d.", a[0], a[1]);
            }
            else if (anc == a[1]) {
                sprintf(buf, "%d is an ancestor of %d.", a[1], a[0]);
            }
            else {
                sprintf(buf, "LCA of %d and %d is %d.", a[0], a[1], anc);
            }
        }
        cout << buf << endl;
    }
    return 0;
}




