#include <bits/stdc++.h>
using namespace std;
// Accepted!
struct Node {
    int next = -1;
    int current = -1;
    int data = -1;
    bool flag = false;
    bool operator<(const Node& o) const {
        if (!flag) return false;
        if (!o.flag) return true;
        return data < o.data;
    }
};

int main() {
    int N;
    int beginNode;
    vector<Node> l;
    l.resize(100001);
    cin >> N >> beginNode;
    if (beginNode == -1) {
        cout << 0 << " " << -1 << endl;
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        cin >> l[tmp].data >> l[tmp].next;
        l[tmp].current = tmp;
    }
    int len = 0;
    for (int i = beginNode; i != -1; i = l[i].next) {
        l[i].flag = true;
        len++;
    }
    char buf[100];
    sort(l.begin(), l.end());
    sprintf(buf, "%d %05d\n", len, l[0].current);
    cout << buf;
    int next;
    for (int i = 0; i < len; ++i) {
        if (i != len - 1)
            next = l[i + 1].current;
        else
            next = -1;
        if (next == -1) {
            sprintf(buf, "%05d %d %d\n", l[i].current, l[i].data, -1);
        }
        else {
            sprintf(buf, "%05d %d %05d\n", l[i].current, l[i].data, next);
        }
        cout << buf;
    }
    return 0;
}
