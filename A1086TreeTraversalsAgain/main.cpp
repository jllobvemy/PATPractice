#include <bits/stdc++.h>
// Accepted!
using namespace std;
int N;

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int data;
};
int total = 0;

Node* create() {
    if (total > N - 1) return nullptr;
    char buf[15];
    cin.getline(buf, 15);
    int data;
    if (buf[1] == 'u') {
        sscanf(buf, "Push %d", &data);
    }
    else {
        return nullptr;
    }
    Node* ret = new Node;
    ret->data = data;
    total++;
    ret->left = create();
    ret->right = create();
    return ret;
}

bool first = true;
void PostOrder(Node* root) {
    if (!root) return;
    PostOrder(root->left);
    PostOrder(root->right);
    if (first) {
        cout << root->data;
        first = false;
    }
    else cout << " " << root->data;
}

int main() {
    cin >> N;
    getchar();
    Node* ans = create();
    PostOrder(ans);
    cout << endl;
    return 0;
}
