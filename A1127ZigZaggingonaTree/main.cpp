#include <bits/stdc++.h>
// Accepted!
using namespace std;
vector<int> PostOrder;
vector<int> InOrder;
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int data;
};

Node* Create(int postLeft, int postRight, int inLeft, int inRight) {
    if (postLeft > postRight) return nullptr;
    Node* ret = new Node;
    ret->data = PostOrder[postRight];
    if (postLeft == postRight) return ret;
    int cnt = 0;
    for (int i = inLeft; i <= inRight; ++i) {
        if (InOrder[i] == PostOrder[postRight]) {
            break;
        }
        cnt++;
    }
    ret->left = Create(postLeft, postLeft + cnt - 1, inLeft, inLeft + cnt - 1);
    ret->right = Create(postLeft + cnt, postRight - 1, inLeft + cnt + 1, inRight);
    return ret;
}
vector<vector<int>> ans;

void ZigzaggingOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        vector<int> tmp;
        while (size--) {
            Node* top = q.front();
            q.pop();
            tmp.push_back(top->data);
            if (top->left) q.push(top->left);
            if (top->right) q.push(top->right);
        }
        ans.push_back(tmp);
    }
}


int main() {
    int N;
    cin >> N;
    PostOrder.resize(N);
    InOrder.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> InOrder[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> PostOrder[i];
    }
    Node* root = Create(0, N - 1, 0, N - 1);
    ZigzaggingOrder(root);
    bool flag = true;
    bool first = true;
    for (auto& v: ans) {
        if (!flag) {
            for (auto it = v.begin(); it != v.end(); it++) {
                if (first) first = false;
                else cout << " ";
                cout << *it;
            }
        }
        else {
            for (auto it = v.rbegin(); it != v.rend(); it++) {
                if (first) first = false;
                else cout << " ";
                cout << *it;
            }
        }
        flag = !flag;
    }

    return 0;
}
