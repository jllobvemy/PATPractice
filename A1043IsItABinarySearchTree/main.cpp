#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int data = INT_MAX;
};
vector<Node> tree;

void insert(Node* &root, int data) {
    if (root == nullptr) {
        root = new Node;
        root->data = data;
        return;
    }
    if (data >= root->data) {
        insert(root->right, data);
    }
    else {
        insert(root->left, data);
    }
}
Node* create(const vector<int>& v) {
    Node* ret = nullptr;
    for (auto e: v) {
        insert(ret, e);
    }
    return ret;
}
vector<int> PreOrderAns;
void PreOrder(Node* root) {
    if (root == nullptr) return;
    PreOrderAns.push_back(root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}
vector<int> ImagePreOrderAns;
void ImagePreOrder(Node* root) {
    if (root == nullptr) return;
    ImagePreOrderAns.push_back(root->data);
    ImagePreOrder(root->right);
    ImagePreOrder(root->left);
}
vector<int> PostOrderAns;
void PostOrder(Node* root) {
    if (root == nullptr) return;
    PostOrder(root->left);
    PostOrder(root->right);
    PostOrderAns.push_back(root->data);
}
vector<int> ImagePostOrderAns;
void ImagePostOrder(Node* root) {
    if (root == nullptr) return;
    ImagePostOrder(root->right);
    ImagePostOrder(root->left);
    ImagePostOrderAns.push_back(root->data);
}



int main() {
    int N;
    cin >> N;
    vector<int> datas;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        datas.push_back(tmp);
    }
    auto root = create(datas);
    PreOrder(root);
    ImagePreOrder(root);
    if (datas == PreOrderAns) {
        bool first = true;
        cout << "YES" << endl;
        PostOrder(root);
        for (auto i: PostOrderAns) {
            if (first) {
                cout << i;
                first = false;
            }
            else {
                cout << " " << i;
            }
        }
    }
    else if (datas == ImagePreOrderAns) {
        bool first = true;
        cout << "YES" << endl;
        ImagePostOrder(root);
        for (auto i: ImagePostOrderAns) {
            if (first) {
                cout << i;
                first = false;
            }
            else {
                cout << " " << i;
            }
        }

    }
    else cout << "NO" << endl;
    return 0;
}
