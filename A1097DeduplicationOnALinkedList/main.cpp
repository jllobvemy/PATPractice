#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 10e4 * 2;
struct Node {
    int index;
    int next;
    int data = INT_MAX;
    int prior = INT_MAX;
    bool operator<(const Node& other) const {
        return prior < other.prior;
    }
};
array<Node, MAXLEN> nodes;
array<bool, MAXLEN> hashtable;

int main() {
    int Start, N;
    cin >> Start >> N;
    for (int i = 0; i < N; ++i) {
        int index;
        cin >> index;
        nodes[index].index = index;
        cin >> nodes[index].data >> nodes[index].next;
    }
    if (nodes[Start].data == INT_MAX) return 1;
    int cnt1 = 0, cnt2 = 0;
    int p = 0;
    for (int i = Start; i != -1; i = nodes[i].next) {
        if (!hashtable[abs(nodes[i].data)]) {
            hashtable[abs(nodes[i].data)] = true;
            cnt1++;
            nodes[i].prior = cnt1;
        }
        else {
            cnt2++;
            nodes[i].prior = (1000000 + cnt2);
        }
    }
    sort(nodes.begin(), nodes.end());

    for (int i = 0; i < cnt1; ++i) {
        char buf[50];
        if (i != cnt1 - 1)
            sprintf(buf, "%05d %d %05d\n", nodes[i].index, nodes[i].data, nodes[i + 1].index);
        else
            sprintf(buf, "%05d %d -1\n", nodes[i].index, nodes[i].data);
        cout << buf;
    }
    for (int i = cnt1; i < cnt2 + cnt1; i++) {
        char buf[50];
        if (i != cnt1 + cnt2 - 1)
            sprintf(buf, "%05d %d %05d\n", nodes[i].index, nodes[i].data, nodes[i + 1].index);
        else
            sprintf(buf, "%05d %d -1\n", nodes[i].index, nodes[i].data);
        cout << buf;
    }
    return 0;
}
