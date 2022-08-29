#include <bits/stdc++.h>
// Accepted!
using namespace std;
vector<int> PreOrder, InOrder;
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int data = -1;
};
Node* create(int PreLeft, int PreRight, int InLeft, int InRight) {
    if (PreLeft > PreRight) return nullptr;
    Node* ret = new Node;
    ret->data = PreOrder[PreLeft];
    if (PreLeft == PreRight) return ret;
    int cnt = 0;
    while (PreOrder[PreLeft] != InOrder[InLeft + cnt]) cnt++;
    ret->left = create(PreLeft + 1, PreLeft + cnt, InLeft, InLeft + cnt - 1);
    ret->right = create(PreLeft + cnt + 1, PreRight, InLeft + cnt + 1, InRight);
    return ret;
}
vector<int> ans;
void PostOrder(Node* root) {
    if (ans.size() > 2) return;
    if (root->left) PostOrder(root->left);
    if (root->right) PostOrder(root->right);
    ans.push_back(root->data);
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        PreOrder.push_back(tmp);
    }

    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        InOrder.push_back(tmp);
    }
    Node* root = create(0, N - 1, 0, N - 1);
    PostOrder(root);
    cout << ans.front() << endl;

    return 0;
}
