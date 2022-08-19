#include <bits/stdc++.h>
// Accepted!
using namespace std;
array<int, 10000000> exits;

int main() {
    ios::sync_with_stdio(false);
    int N;
    int sum = 0;
    cin >> N;
    for (int i = 2; i <= N; ++i) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        exits[i] = sum;
    }
    int tmp;
    cin >> tmp;
    sum += tmp;
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        if (a == b) cout << 0 << '\n';
        else {
            if (a > b) swap(a, b);
            int dis = exits[b] - exits[a];
            int ans = min(dis, sum - dis);
            cout << ans << '\n';
        }
    }
    return 0;
}
