#include <bits/stdc++.h>
// Not Ac. 22/25
using namespace std;
struct Node {
    int data;
    int next;
    int prev;
};

int main() {
    vector<Node> l;
    l.resize(100001);
    int beginAddr, N;
    cin >> beginAddr >> N;
    map<int, bool> dup;
    for (int i = 0; i < N; ++i) {
        int addr;
        cin >> addr;
        cin >> l[addr].data >> l[addr].next;
        if (l[addr].next != -1)
            l[l[addr].next].prev = addr;
    }
    bool firstDup = false;
    int firstDupAddr = -1;
    int lastDupAddr = -1;
    for (int i = beginAddr; i != -1; i = l[i].next) {
        if (dup[abs(l[i].data)]) {
            if (!firstDup)  {
                firstDupAddr = i;
                firstDup = true;
                lastDupAddr = i;
            }
            else {
                l[lastDupAddr].next = i;
                lastDupAddr = i;
            }
            l[l[i].prev].next = l[i].next;
            if (l[i].next != -1) l[l[i].next].prev = l[i].prev;
        }
        else {
            dup[abs(l[i].data)] = true;
        }
    }
    char buf[100];
    for (int i = beginAddr; i != -1; i = l[i].next) {
        if (l[i].next != -1)
            sprintf(buf, "%05d %d %05d\n", i, l[i].data, l[i].next);
        else {
            sprintf(buf, "%05d %d %d\n", i, l[i].data, l[i].next);
        }
        cout << buf;
    }
    if (firstDupAddr == -1) {
        return 0;
    }
    l[lastDupAddr].next = -1;
    for (int i = firstDupAddr; i != -1; i = l[i].next) {
        if (l[i].next != -1)
            sprintf(buf, "%05d %d %05d\n", i, l[i].data, l[i].next);
        else {
            sprintf(buf, "%05d %d %d\n", i, l[i].data, l[i].next);
        }
        cout << buf;
    }
    return 0;
}
