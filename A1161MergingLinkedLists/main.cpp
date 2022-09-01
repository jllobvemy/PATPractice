#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 100000;
vector<int> l1, l2, ans;
struct Node {
    int next = -1;
    int data;
};
array<Node, MAXLEN> LIST;


int main() {
    int start1, start2, N;
    cin >> start1 >> start2 >> N;
    for (int i = 0; i < N; ++i) {
        int index, data, next;
        cin >> index >> data >> next;
        LIST[index].data = data;
        LIST[index].next = next;
    }
    for (int i = start1; i != -1; i = LIST[i].next) {
        l1.push_back(i);
    }
    for (int i = start2; i != -1; i = LIST[i].next) {
        l2.push_back(i);
    }
    if (l2.size() > l1.size()) l1.swap(l2);
    for (int i = 0, j = l2.size() - 1; i < l1.size(); ++i) {
        ans.push_back(l1[i]);
        if (i % 2 == 1 && j >= 0) ans.push_back(l2[j--]);
    }
    char buf[100];
    for (int i = 0; i < ans.size(); ++i) {
        if (i != ans.size() - 1)
            sprintf(buf, "%05d %d %05d\n", ans[i], LIST[ans[i]].data, ans[i + 1]);
        else
            sprintf(buf, "%05d %d -1\n", ans[i], LIST[ans[i]].data);
        cout << buf;
    }

    return 0;
}
