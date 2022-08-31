#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct Node {
    int data = -1;
    Node* left = nullptr;
    Node* right = nullptr;
};
int N;
vector<int> InOrderV;
vector<int> HeapOrderV;
vector<int> levelOrderV;
void levelOrder(Node* r) {
    queue<Node*> q;
    q.push(r);
    while (!q.empty()) {
        Node* tmp = q.front();
        q.pop();
        if (tmp->left) q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
        levelOrderV.push_back(tmp->data);
    }
}

Node* Create(int inLeft, int inRight, vector<int>& heapOrder) {
    if (heapOrder.empty()) return nullptr;
    Node* ret = new Node;
    ret->data = heapOrder.front();
    if (heapOrder.size() == 1) return ret;
    int cnt = 0;
    while (heapOrder.front() != InOrderV[inLeft + cnt]) cnt++;
    vector<int> leftV;
    vector<int> rightV;
    for (auto e: heapOrder) {
        for (int i = inLeft; i < inLeft + cnt; ++i) {
            if (InOrderV[i] == e) {
                leftV.push_back(e);
                break;
            }
        }
    }
    for (auto e: heapOrder) {
        for (int i = inLeft + cnt + 1; i <= inRight; ++i) {
            if (InOrderV[i] == e) {
                rightV.push_back(e);
                break;
            }
        }
    }
    ret->left = Create(inLeft, inLeft + cnt - 1, leftV);
    ret->right = Create(inLeft + cnt + 1, inRight, rightV);
    return ret;
}

void inOrder(Node* n) {
    if (n->left) inOrder(n->left);
    cout << n->data << " ";
    if (n->right) inOrder(n->right);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        InOrderV.push_back(tmp);
    }
    HeapOrderV = InOrderV;
    sort(HeapOrderV.begin(), HeapOrderV.end());
    Node* root = Create(0, N - 1, HeapOrderV);
    levelOrder(root);
    bool first = true;
    for (int i = 0; i < N; ++i) {
        if (first) first = false;
        else cout << " ";
        cout << levelOrderV[i];
    }
//    inOrder(root);

    return 0;
}
