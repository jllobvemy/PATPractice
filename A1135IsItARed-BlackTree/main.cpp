#include <bits/stdc++.h>
// Not Ac.
using namespace std;
vector<int> InOrder, PreOrder;
struct Node {
    int data = INT_MAX;
    Node* left = nullptr;
    Node* right = nullptr;
    int Height = 1;
};
Node* Create(int PreLeft, int PreRight, int InLeft, int InRight) {
    if (PreLeft > PreRight) return nullptr;
    Node* ret = new Node;
    ret->data = PreOrder[PreLeft];
    if (PreLeft == PreRight) return ret;
    int cnt = 0;
    while (PreOrder[PreLeft] != InOrder[InLeft + cnt]) cnt++;
    ret->left = Create(PreLeft + 1, PreLeft + cnt, InLeft, InLeft + cnt - 1);
    ret->right = Create(PreLeft + cnt + 1, PreRight, InLeft + cnt + 1, InRight);
    return ret;
}

int GetHeight(Node* n) {
    if (!n) return 1;
    return n->Height;
}

void UpdateHeight(Node* root) {
    if (root->left) UpdateHeight(root->left);
    if (root->right) UpdateHeight(root->right);
    if (root->data > 0) root->Height = max(GetHeight(root->left), GetHeight(root->right)) + 1;
    else root->Height = max(GetHeight(root->left), GetHeight(root->right));
}

bool JHTmp = true;
void JudgeHeight(Node* root) {
    if (root->left && root->right) {
        if (root->left->Height != root->right->Height) JHTmp = false;
    }
    if (root->left) JudgeHeight(root->left);
    if (root->right) JudgeHeight(root->right);
}
bool JCTmp = true;
void JudgeColor(Node* root) {
    if (root->data < 0) {
        if (root->left && root->left->data < 0) JCTmp = false;
        if (root->right && root->right->data < 0) JCTmp = false;
    }
    if (root->left) JudgeColor(root->left);
    if (root->right) JudgeColor(root->right);
}


int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        InOrder.resize(K, 0);
        PreOrder.resize(K, 0);
        for (int j = 0; j < K; ++j) {
            int tmp;
            cin >> tmp;
            InOrder[j] = PreOrder[j] = tmp;
        }
        sort(InOrder.begin(), InOrder.end(), [](int a, int b){
            return abs(a) < abs(b);
        });
        Node* root = Create(0, K - 1, 0, K - 1);
        JHTmp = true;
        JCTmp = true;
        UpdateHeight(root);
        JudgeHeight(root);
        JudgeColor(root);
        if (PreOrder[0] > 0 && JHTmp && JCTmp) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}