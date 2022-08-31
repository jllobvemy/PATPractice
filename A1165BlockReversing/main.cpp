#include <bits/stdc++.h>
// Accepted
using namespace std;
struct Node {
    int order = INT_MAX;
    int data = -1;
    int index = -1;
    int next = -1;
    int block = -1;
    bool operator<(Node& other) const {
        if (block > other.block) return true;
        else if (block == other.block) return order < other.order;
        return false;
    }
};
array<Node, 100100> nodes;


int main() {
    int start, N, K;
    cin >> start >> N >> K;
    for (int i = 0; i < N; ++i) {
        int index, data, next;
        cin >> index >> data >> next;
        nodes[index].index = index;
        nodes[index].data = data;
        nodes[index].next = next;
    }
    int cnt = 0;
    int block = 0;
    for (int i = start; i != -1; i = nodes[i].next) {
        if (cnt % K == 0) block += 10;
        nodes[i].order = cnt;
        nodes[i].block = block;
        cnt++;
    }
    sort(nodes.begin(), nodes.end());
    char buf[100];
    for (int i = 0; i < cnt; ++i) {
        if (i != cnt - 1) {
            sprintf(buf, "%05d %d %05d\n", nodes[i].index, nodes[i].data, nodes[i + 1].index);
        }
        else {
            sprintf(buf, "%05d %d -1\n", nodes[i].index, nodes[i].data);
        }
        cout << buf;
    }
    return 0;
}
