#include <bits/stdc++.h>
// Not Ac
using namespace std;
constexpr int MAXLEN = 200010;
struct Node {
    double order = DBL_MAX;
    int data = -1;
    int index = -1;
    int next = -1;
    bool operator<(const Node& other) const {
        return order < other.order;
    }
};
array<Node, MAXLEN> List;
int main() {
    int start1, start2, N;
    cin >> start1 >> start2 >> N;
    for (int i = 0; i < N; ++i) {
        int index, data, next;
        cin >> index >> data >> next;
        List[index].data = data;
        List[index].next = next;
        List[index].index = index;
    }
    int len1 = 0, len2 = 0;
    for (int i = start1; i != -1; i = List[i].next) {
        len1++;
    }
    for (int i = start2; i != -1; i = List[i].next) {
        len2++;
    }
    int cnt = 0;
    stack<double> q;
    int i1, i2;
    if (len1 > len2) {
        i1 = start1;
        i2 = start2;
    }
    else {
        i1 = start2;
        i2 = start1;
    }
    for (; i1 != -1; i1 = List[i1].next) {
        cnt++;
        List[i1].order = cnt;
        if (cnt % 2 == 0) {
            q.push(cnt + .5);
        }
    }
    for (; i2 != -1; i2 = List[i2].next) {
        List[i2].order = q.top();
        q.pop();
    }
    sort(List.begin(), List.end());
    char buf[100];
    int len = len1 + len2;
    for (int i = 0; i < len; ++i) {
        if (i != len - 1) {
            sprintf(buf, "%05d %d %05d\n", List[i].index, List[i].data, List[i + 1].index);
        }
        else {
            sprintf(buf, "%05d %d -1\n", List[i].index, List[i].data);
        }
        cout << buf;
    }
    return 0;
}
