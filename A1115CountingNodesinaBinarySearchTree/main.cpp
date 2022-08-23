#include <bits/stdc++.h>
// Accepted!
using namespace std;

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int data = INT_MAX;
};

void Insert(Node* root, int data) {
    if (data <= root->data) {
        if (root->left) {
            Insert(root->left, data);
        }
        else {
            Node* tmp = new Node;
            tmp->data = data;
            root->left = tmp;
        }
    }
    else {
        if (root->right) {
            Insert(root->right, data);
        }
        else {
            Node* tmp = new Node;
            tmp->data = data;
            root->right = tmp;
        }
    }
}
int MaxLevel = 1;
pair<int, int> LevelTraverse(Node* root) {
    queue<Node*> q;
    q.push(root);
    int n1 = 0, n2 = 0;
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        level++;
        if (level == MaxLevel - 1) {
            n1 = size;
        }
        if (level == MaxLevel) {
            n2 = size;
        }
        while (size--) {
            auto top = q.front();
            q.pop();
            if (top->left) q.push(top->left);
            if (top->right) q.push(top->right);
        }
    }
    return {n1, n2};
}
int CountLevel(Node* root) {
    queue<Node*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        level++;
        while (size--) {
            auto top = q.front();
            q.pop();
            if (top->left) q.push(top->left);
            if (top->right) q.push(top->right);
        }
    }
    return level;
}

int main() {
    int N;
    cin >> N;
    Node* root = new Node;
    cin >> root->data;
    for (int i = 0; i < N - 1; ++i) {
        int tmp;
        cin >> tmp;
        Insert(root, tmp);
    }
    MaxLevel = CountLevel(root);
    auto [n1, n2] = LevelTraverse(root);
    cout << n2 << " + " << n1 << " = " << n1 + n2;
    return 0;
}
