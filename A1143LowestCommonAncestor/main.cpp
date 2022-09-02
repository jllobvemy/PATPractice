#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    int data;
};

vector<int> PreOrder;
vector<int> InOrder;
unordered_map<int, Node*> value2node;

Node* Create(Node* parent, int PreLeft, int PreRight, int InLeft, int InRight) {
    if (PreLeft > PreRight) return nullptr;
    Node* ret = new Node;
    ret->data = PreOrder[PreLeft];
    ret->parent = parent;
    value2node[ret->data] = ret;
    if (PreLeft == PreRight) return ret;
    int cnt = 0;
    while (PreOrder[PreLeft] != InOrder[InLeft + cnt]) cnt++;
    ret->left = Create(ret, PreLeft + 1, PreLeft + cnt, InLeft, InLeft + cnt - 1);
    ret->right = Create(ret, PreLeft + cnt + 1, PreRight, InLeft + cnt + 1, InRight);
    return ret;
}

int findLCA(int a, int b) {
    Node* pa = value2node[a];
    Node* pb = value2node[b];
    vector<int> aAncestor;
    vector<int> bAncestor;
    for (auto i = pa; i != nullptr; i = i->parent) {
        aAncestor.push_back(i->data);
    }
    for (auto i = pb; i != nullptr; i = i->parent) {
        bAncestor.push_back(i->data);
    }
    int ii;
    if (aAncestor.size() > bAncestor.size()) aAncestor.swap(bAncestor);
    std::reverse(aAncestor.begin(), aAncestor.end());
    std::reverse(bAncestor.begin(), bAncestor.end());
    for (ii = 0; ii < aAncestor.size(); ii++) {
        if (aAncestor[ii] != bAncestor[ii]) {
            break;
        }
    }
    return aAncestor[ii - 1];
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
    char buf[100];
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (value2node[a] == nullptr && value2node[b] != nullptr) {
            sprintf(buf, "ERROR: %d is not found.\n", a);
        }
        else if (value2node[a] != nullptr && value2node[b] == nullptr) {
            sprintf(buf, "ERROR: %d is not found.\n", b);
        }
        else if (value2node[a] == nullptr && value2node[b] == nullptr) {
            sprintf(buf, "ERROR: %d and %d are not found.\n", a, b);
        }
        else {
            int A = findLCA(a, b);
            if (A == a) {
                sprintf(buf, "%d is an ancestor of %d.\n", a, b);
            }
            else if (A == b) {
                sprintf(buf, "%d is an ancestor of %d.\n", b, a);
            }
            else {
                sprintf(buf, "LCA of %d and %d is %d.\n", a, b, A);
            }
        }
        cout << buf;
    }
    return 0;
}




