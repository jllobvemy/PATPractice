#include <bits/stdc++.h>
// Accepted!
using namespace std;
int N;
long P;

vector<int> S;

int main() {
    cin >> N >> P;
    S.reserve(10040);
    if (P < 0.0001 ) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        S.push_back(tmp);
    }
    std::sort(S.begin(), S.end());
    int res = 1;
    for (auto it = S.begin(); it != S.end(); it++) {
        auto dis = std::upper_bound(S.begin(), S.end(), (*it * P));
        res = max(res, (int)distance(it, dis));
    }
    cout << res;
    return 0;
}
