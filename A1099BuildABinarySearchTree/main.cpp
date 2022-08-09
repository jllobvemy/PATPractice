#include <bits/stdc++.h>
// Accepted!
using namespace std;
vector<int> values;
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int data = INT_MAX;
};
int N;
int valueIndex = 0;
void InOrder(Node* root) {
    if (root == nullptr) return;
    InOrder(root->left);
    root->data = values[valueIndex++];
    InOrder(root->right);
}

bool first = true;
void LevelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* tmp = q.front();
        q.pop();
        if (first) {
            first = false;
            cout << tmp->data;
        }
        else {
            cout << " " << tmp->data;
        }
        if (tmp->left) q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
    }
}

int main() {
    cin >> N;
    vector<Node*> nodes;
    nodes.reserve(N);
    for (int i = 0; i < N; ++i) {
        nodes.push_back(new Node);
    }
    for (int i = 0; i < N; ++i) {
        int left;
        int right;
        cin >> left >> right;
        if (left != -1) nodes[i]->left = nodes[left];
        if (right != -1) nodes[i]->right = nodes[right];
    }
    values.reserve(N);
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        values.push_back(tmp);
    }
    sort(values.begin(), values.end());
    InOrder(nodes[0]);
    LevelOrder(nodes[0]);
    return 0;
}