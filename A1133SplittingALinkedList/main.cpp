#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 100010;
int N, K;
struct Node {
    int index;
    int data;
    int next;
    int order = INT_MAX;
    bool operator<(const Node& other) const {
        return order < other.order;
    }
};


int main() {
    int Begin;
    cin >> Begin >> N >> K;
    vector<Node> nodes( MAXLEN);
    for (int i = 0; i < N; ++i) {
        int index;
        cin >> index;
        cin >> nodes[index].data >> nodes[index].next;
        nodes[index].index = index;
    }
    int num = 0;
    for (int i = Begin; i != -1 ; i = nodes[i].next) {
        num++;
        if (nodes[i].data < 0) nodes[i].order = num - MAXLEN;
        else if (nodes[i].data >= 0 && nodes[i].data <= K) nodes[i].order = num + MAXLEN;
        else nodes[i].order = num + MAXLEN * 2;
    }
    sort(nodes.begin(), nodes.end());
    char buf[100];
    for (int i = 0; i < num; ++i) {
        if (nodes[i].order == -1) return 1;
        if (i != num - 1) {
            sprintf(buf, "%05d %d %05d\n", nodes[i].index, nodes[i].data, nodes[i + 1].index);
        }
        else {
            sprintf(buf, "%05d %d -1\n", nodes[i].index, nodes[i].data);
        }
        cout << buf;
    }
    return 0;
}
