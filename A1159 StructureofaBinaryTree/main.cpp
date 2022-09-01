#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr array<const char*, 7> regexs = {
        R"((\d+) is the root)",
        R"((\d+) and (\d+) are siblings)",
        R"((\d+) is the parent of (\d+))",
        R"((\d+) is the left child of (\d+))",
        R"((\d+) is the right child of (\d+))",
        R"((\d+) and (\d+) are on the same level)",
        R"(It is a full tree)"
};
struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    Node* parent = nullptr;
    int depth = 0;
    int degree = 0;
    int data = -1;
};
map<int, Node*> FindNode;
vector<int> PostOrder;
vector<int> InOrder;
bool fullTree = true;
Node* Create(Node* parent, int postLeft, int postRight, int inLeft, int inRight, int depth) {
    if (postLeft > postRight) return nullptr;
    Node* ret = new Node;
    ret->parent = parent;
    ret->data = PostOrder[postRight];
    ret->depth = depth;
    FindNode[ret->data] = ret;
    if (postRight == postLeft) return ret;
    int cnt = 0;
    while (PostOrder[postRight] != InOrder[inLeft + cnt]) cnt++;
    ret->left = Create(ret, postLeft, postLeft + cnt - 1, inLeft, inLeft + cnt - 1, depth + 1);
    ret->right = Create(ret, postLeft + cnt, postRight - 1, inLeft + cnt + 1, inRight, depth + 1);
    if (ret->left && ret->right) ret->degree = 2;
    else if ((ret->left == nullptr) ^ (ret->right == nullptr)) {
        ret->degree = 1;
        fullTree = false;
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    PostOrder.resize(N);
    InOrder.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> PostOrder[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> InOrder[i];
    }
    Node* root = Create(nullptr, 0, N - 1, 0, N - 1, 0);
    int K;
    cin >> K;
    char buf[100];
    cin.get();
    for (int i = 0; i < K; ++i) {
        string q;
        getline(cin, q);
        int j;
        smatch res;
        for (j = 0; j < regexs.size(); j++) {
            regex base(regexs[j]);
            if (regex_match(q, res, base)) {
                break;
            }
        }
        bool ans = false;
        Node* a, *b;
        switch (j) {
            case 0:
                if (!FindNode[stoi(res[1])]->parent)
                    ans = true;
                break;
            case 1:
                a = FindNode[stoi(res[1])];
                b = FindNode[stoi(res[2])];
                if (a->parent && a->parent->degree > 1) {
                    if (a->parent->left != a) { // a为右
                        ans = a->parent->left->data == b->data;
                    }
                    else {
                        ans = a->parent->right->data == b->data;
                    }
                }
                else ans = false;
                break;
            case 2:
                a = FindNode[stoi(res[1])];
                b = FindNode[stoi(res[2])];
                ans = b->parent == a;
                break;
            case 3:
                a = FindNode[stoi(res[1])];
                b = FindNode[stoi(res[2])];
                ans = b->left == a;
                break;
            case 4:
                a = FindNode[stoi(res[1])];
                b = FindNode[stoi(res[2])];
                ans = b->right == a;
                break;
            case 5:
                a = FindNode[stoi(res[1])];
                b = FindNode[stoi(res[2])];
                ans = a->depth == b->depth;
                break;
            case 6:
                ans = fullTree;
                break;
            default:
                return 1;
        }
        cout << (ans? "Yes": "No") << endl;
    }
    return 0;
}
