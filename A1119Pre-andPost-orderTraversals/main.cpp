#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 1000;
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int data;
};
vector<int> PreOrderRaw;
vector<int> PostOrderRaw;
bool Unique = true;
Node* Create(int preleft, int preright, int postleft, int postright) {
    if (preleft > preright) return nullptr;
    Node* ret = new Node;
    ret->data = PreOrderRaw[preleft];
    if (preleft == preright) return ret;
    int cnt = 0;
    while (PostOrderRaw[postleft + cnt] != PreOrderRaw[preleft + 1]) cnt++;
    cnt++;
    if (cnt == 1 && preleft + cnt == preright) Unique = false;
    ret->left = Create(preleft + 1, preleft + cnt, postleft, postleft + cnt - 1);
    ret->right = Create(preleft + cnt + 1, preright, postleft + cnt, postright - 1);
    return ret;
}

vector<Node*> InOrderVec;
void InOrder(Node* root) {
    if (root->left) InOrder(root->left);
    InOrderVec.push_back(root);
    if (root->right) InOrder(root->right);
}

int main() {
    int N;
    cin >> N;
    Node* root;
    PreOrderRaw.resize(N);
    PostOrderRaw.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> PreOrderRaw[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> PostOrderRaw[i];
    }
    root = Create(0, N - 1, 0, N - 1);
    InOrder(root);
    if (Unique) cout << "Yes" << endl;
    else cout << "No" << endl;
    bool first = true;
    for (auto e: InOrderVec) {
        if (first) {
            first = false;
            cout << e->data;
        }
        else cout << " " << e->data;
    }
    return 0;
}
