#include <bits/stdc++.h>
// Accepted!
using namespace std;
vector<int> postOrder;
vector<int> inOrder;

struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int data;
};

Node* create(int pbegin, int pend, int ibegin, int iend) {
    if (pbegin > pend) return nullptr;
    int data = postOrder[pend];
    auto node = new Node;
    node->data = data;
    int rootposi = find(inOrder.begin() + ibegin, inOrder.begin() + iend, data) - inOrder.begin();
    int leftsize = rootposi - ibegin;
    node->left = create(pbegin, pbegin + leftsize - 1, ibegin, ibegin + leftsize - 1);
    node->right = create(pbegin + leftsize, pend - 1, rootposi + 1, iend);
    return node;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        postOrder.push_back(tmp);
    }
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        inOrder.push_back(tmp);
    }
    auto ret = create(0, N - 1, 0, N - 1);
    queue<Node*> q;
    q.push(ret);
    bool first = true;
    while (!q.empty()) {
        if (first) {
            cout << q.front()->data;
            first = false;
        }
        else cout << " " << q.front()->data;
        if (q.front()->left) q.push(q.front()->left);
        if (q.front()->right)  q.push(q.front()->right);
        q.pop();
    }
    cout << endl;
    return 0;
}
