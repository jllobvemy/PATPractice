#include <bits/stdc++.h>
// Accepted!
using namespace std;
int N;
struct Node {
    int left = -1;
    int right = -1;
    int data = 0;
};
vector<Node> tree;

bool first = true;
void InvertInOrder(int root) {
    if (root == -1) return;
    InvertInOrder(tree[root].right);
    if (first) {
        first = false;
        cout << root;
    }
    else {
        cout << " " << root;
    }
    InvertInOrder(tree[root].left);
}

void InvertLevelOrder(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        root = q.front();
        if (first) {
            cout << q.front();
            first = false;
        }
        else {
            cout << " " << q.front();
        }
        q.pop();
        if (tree[root].right != -1)
            q.push(tree[root].right);
        if (tree[root].left != -1)
            q.push(tree[root].left);

    }
}



int main() {
    cin >> N;
    set<int> roots;
    for (int i = 0; i < N; ++i) {
        roots.insert(i);
    }
    tree.resize(N);
    getchar();
    for (int i = 0; i < N; ++i) {
        char buf[10];
        cin.getline(buf, 10);
        char left, right;
        sscanf(buf, "%c %c", &left, &right);
        if (left != '-') {
            roots.erase(left - '0');
            tree[i].left = left - '0';
        }
        if (right != '-') {
            roots.erase(right - '0');
            tree[i].right = right - '0';
        }
    }
    int root = *roots.begin();
    first = true;
    InvertLevelOrder(root);
    cout << endl;
    first = true;
    InvertInOrder(root);
    return 0;
}
