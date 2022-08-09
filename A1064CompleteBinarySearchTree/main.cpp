#include <bits/stdc++.h>
// Accepted!
using namespace std;
int N;
vector<int> tree;
vector<int> datas;
int dataPosi = 0;

void InOrder(int root) {
    if (root > N) return;
    InOrder(root * 2);
    tree[root] = datas[dataPosi++];
    InOrder(root * 2 + 1);
}
int main() {
    cin >> N;
    tree.resize(N + 1, -1);
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        datas.push_back(tmp);
    }
    sort(datas.begin(), datas.end());
    InOrder(1);
    bool first = true;
    for (int i = 1; i <= N; ++i) {
        if (first) {
            first = false;
            cout << tree[i];
        }
        else {
            cout << " " << tree[i];
        }
    }
    cout << endl;
    return 0;
}
