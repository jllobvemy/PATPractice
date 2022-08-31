#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXSIZE = 210;
array<array<bool, MAXSIZE>, MAXSIZE> G;
int N, M;
int judge(vector<int>& vi) {
    // 1: ok
    // 0: need help
    // -k: invite k
    for (int i = 0; i < vi.size(); ++i) {
        for (int j = i + 1; j < vi.size(); ++j) {
            if (!G[vi[i]][vi[j]]) return 0;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= N; ++i) {
        int cnt = 0;
        for (auto e: vi) {
            if (G[e][i]) cnt++;
        }
        if (cnt == vi.size()) ans.push_back(i);
    }
    if (ans.empty()) return 1;
    sort(ans.begin(), ans.end());
    return -ans[0];
}


int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a][b] = true;
        G[b][a] = true;
    }
    int K;
    cin >> K;
    char buf[100];
    for (int i = 0; i < K; ++i) {
        int num;
        cin >> num;
        vector<int> vi(num);
        for (int j = 0; j < num; ++j) {
            cin >> vi[j];
        }
        int res = judge(vi);
        if (res == 1) {
            sprintf(buf, "Area %d is OK.", i + 1);
        }
        else if (res == 0) {
            sprintf(buf, "Area %d needs help.", i + 1);
        }
        else {
            sprintf(buf, "Area %d may invite more people, such as %d.", i + 1, -res);
        }
        cout << buf << endl;
    }

    return 0;
}
