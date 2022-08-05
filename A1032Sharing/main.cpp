#include <bits/stdc++.h>
// Accepted!
using namespace std;
class Node {
public:
    char data = -1;
    int next = -1;
    bool flag = false;
};

int main() {
    vector<Node> List{};
    List.resize(100003);
    int s1begin, s2begin, N;
    cin >> s1begin >> s2begin >> N;
    if (s1begin == s2begin)  {
        char buf[10];
        sprintf(buf, "%05d", s1begin);
        cout << buf;
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        int curr, next;
        char data;
        cin >> curr >> data >> next;
        List[curr].data = data;
        List[curr].next = next;
    }
    int res = -1;
    for (int currentNode = s1begin; currentNode != -1; currentNode = List[currentNode].next) {
        List[currentNode].flag = true;
    }
    for (int currentNode = s2begin; currentNode != -1; currentNode = List[currentNode].next) {
        if (List[currentNode].flag) {
            res = currentNode;
            break;
        }
    }
    if (res != -1) {
        char buf[10];
        sprintf(buf, "%05d", res);
        cout << buf;
    }
    else {
        cout << -1;
    }
    return 0;
}
