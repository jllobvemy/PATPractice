#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int data = INT_MAX;
    int height = 1;
};

int GetHeight(Node* node) {
    if (!node) return 0;
    return node->height;
}

void UpdateHeight(Node* node) {
    node->height = max(GetHeight(node->left), GetHeight(node->right)) + 1;
}

int GetBalancedFactor(Node* node) {
    return GetHeight(node->left) - GetHeight(node->right);
}

void R(Node* &node) {
    Node* tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    UpdateHeight(node);
    UpdateHeight(tmp);
    node = tmp;
}

void L(Node* &node) {
    Node* tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    UpdateHeight(node);
    UpdateHeight(tmp);
    node = tmp;
}

void insert(Node* &root, int data) {
    if (!root) {
        root = new Node;
        root->data = data;
        return;
    }
    if (data <= root->data) {
        insert(root->left, data);
    }
    else {
        insert(root->right, data);
    }
    UpdateHeight(root);
    if (GetBalancedFactor(root) == 2) {
        if (GetBalancedFactor(root->left) == 1) {
            R(root);
        }
        else {
            L(root->left);
            R(root);
        }
    }
    else if (GetBalancedFactor(root) == -2) {
        if (GetBalancedFactor(root->right) == -1) {
            L(root);
        }
        else {
            R(root->right);
            L(root);
        }
    }
}


int main() {
    Node* root = nullptr;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        insert(root, tmp);
    }
    cout << root->data;
    return 0;
}
