#include <bits/stdc++.h>
// Accepted! 并查集
using namespace std;
constexpr int MAXLEN = 1050;
array<int, MAXLEN> father;
int N, M, K;

int findFather(int a) {
    if (a == father[a]) return a;
    father[a] = findFather(father[a]);
    return father[a];
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa != fb) {
        father[fb] = fa;
    }
}

void init() {
    for (int i = 0; i < MAXLEN; ++i) {
        father[i] = i;
    }
}

int findNum() {
    int ret = 0;
    for (int i = 1; i <= N; ++i) {
        if (father[i] == i) ret++;
    }
    return ret;
}

int main() {
    cin >> N >> M >> K;
    vector<pair<int, int>> input;
    input.resize(M);
    for (int i = 0; i < M; ++i) {
        int c1, c2;
        cin >> c1 >> c2;
        input[i] = {c1, c2};
    }
    for (int i = 0; i < K; ++i) {
        init();
        int d;
        cin >> d;
        for (int j = 0; j < M; ++j) {
            int c1 = input[j].first;
            int c2 = input[j].second;
            if (c1 != d && c2 != d) {
                Union(c1, c2);
            }
        }
        cout << findNum() - 2 << endl;
    }
}