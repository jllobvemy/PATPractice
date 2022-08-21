#include <bits/stdc++.h>
// Accepted!
using namespace std;

struct Node {
    int index;
    int data;
    int priority = INT_MAX;
    int next;
    bool operator<(const Node& other) const {
        return priority < other.priority;
    }
};
array<Node, 100050> nodes;

int main() {
    int Start, N, K;
    cin >> Start >> N >> K;
    for (int i = 0; i < N; ++i) {
        int index;
        cin >> index;
        nodes[index].index = index;
        cin >> nodes[index].data;
        cin >> nodes[index].next;
    }
    int i = Start;
    int cnt = 0;
    do {
        nodes[i].priority = cnt++;
        i = nodes[i].next;
    } while (i != -1);
    sort(nodes.begin(), nodes.end());
    int beg = 0;
    int end = beg + K;
    while (end <= cnt) {
        reverse(nodes.begin() + beg, nodes.begin() + end);
        beg = end;
        end += K;
    }
    char buf[50];
    for (int j = 0; j < cnt; ++j) {
        if (j != cnt -1)
            sprintf(buf, "%05d %d %05d\n", nodes[j].index, nodes[j].data, nodes[j + 1].index);
        else
            sprintf(buf, "%05d %d %d\n", nodes[j].index, nodes[j].data, -1);
        cout << buf;
    }
    return 0;
}
