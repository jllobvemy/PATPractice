#include <bits/stdc++.h>
using namespace std;
constexpr int MAXLEN = 1010;
array<int, MAXLEN> tree;
int N;

vector<int> ans;
bool flag = true;
void InOrder(int n) {
    if (tree[n] == -1) return;
    int left = n * 2;
    int right = left + 1;
    if (left <= N) {
        if (tree[left] >= tree[n]) flag = false;
        InOrder(n * 2);
    }
    ans.push_back(tree[n]);
    if (right <= N) {
        if (tree[right] < tree[n]) flag = false;
        InOrder(n * 2 + 1);
    }
}

int main() {
    cin >> N;
    fill(tree.begin(), tree.end(), -1);
    for (int i = 1; i <= N; ++i) {
        cin >> tree[i];
    }
    InOrder(1);
    cout << (flag? "YES": "NO") << endl;
    bool first = true;
    for (auto i: ans) {
        if (first) first = false;
        else cout << " ";
        cout << i;
    }
    return 0;
}
