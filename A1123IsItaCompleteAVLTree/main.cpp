#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int data;
    int height = 1;
};
int GetHeight(Node* n) {
    if (!n) return 0;
    return n->height;
}

void UpdateHeight(Node* n) {
    if (n->left) UpdateHeight(n->left);
    if (n->right) UpdateHeight(n->right);
    n->height = max(GetHeight(n->left), GetHeight(n->right)) + 1;
}

void R(Node*& n) {
    auto tmp = n->left;
    n->left = n->left->right;
    tmp->right = n;
    n = tmp;
}

void L(Node*& n) {
    auto tmp = n->right;
    n->right = n->right->left;
    tmp->left = n;
    n = tmp;
}

void Insert(Node*& root, int n) {
    if (!root) {
        root = new Node;
        root->data = n;
    }
    else {
        if (n > root->data) Insert(root->right, n);
        if (n < root->data) Insert(root->left, n);
        UpdateHeight(root);
    }
    int dif = GetHeight(root->left) - GetHeight(root->right);
    if (dif == 2) {
        int dif2 = GetHeight(root->left->left) - GetHeight(root->left->right);
        if (dif2 == 1) {
            R(root);
        }
        else if (dif2 == -1) {
            L(root->left);
            R(root);
        }
        else exit(2);
    }
    if (dif == -2) {
        int dif2 = GetHeight(root->right->right) - GetHeight(root->right->left);
        if (dif2 == 1) {
            L(root);
        }
        else if (dif2 == -1) {
            R(root->right);
            L(root);
        }
    }
}

void LevelTraverse(Node* root) {
    queue<Node*> q;
    q.push(root);
    bool first = true;
    bool isComplete = true;
    while (!q.empty()) {
        if (first) first = false;
        else cout << " ";
        auto tmp = q.front();
        cout << tmp->data;
        q.pop();
        if (tmp->left) q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
        if (!tmp->left && tmp->right) isComplete = false;
        if ((tmp->left && !tmp->right) || (!tmp->left && !tmp->right)) {
            while (!q.empty()) {
                tmp = q.front();
                cout << " " << tmp->data;
                q.pop();
                if (tmp->left || tmp->right) isComplete = false;
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
    }
    cout << endl;
    if (isComplete) cout << "YES";
    else cout << "NO";
}


int main() {
    Node* root = nullptr;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        Insert(root, tmp);
    }
    LevelTraverse(root);
    return 0;
}
