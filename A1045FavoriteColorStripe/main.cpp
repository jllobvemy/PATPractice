#include <bits/stdc++.h>
// Accepted!
using namespace std;
int CurtIdx = 0;

int main() {
    int NNN;
    cin >> NNN;
    int N;
    cin >> N;
    vector<int> ColorOrder(250, -1);
    for (int i = 1; i <= N; ++i) {
        int tmp;
        cin >> tmp;
        ColorOrder.at(tmp) = ++CurtIdx;
    }
    int M;
    cin >> M;
    vector<int> dp(M, 0);
    vector<int> colors;
    for (int i = 0; i < M; ++i) {
        int tmp;
        cin >> tmp;
        if (ColorOrder[tmp] != -1) {
            dp[i] = 1;
            colors.push_back(tmp);
        }
    }
    int ans = -1;
    for (int i = 0; i < colors.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (dp.at(j) != 0 && dp.at(j) + 1 > dp.at(i) && ColorOrder.at(colors[i]) >= ColorOrder.at(colors[j])) {
                dp.at(i) = dp.at(j) + 1;
            }
        }
        ans = max(ans, dp.at(i));
    }
    cout << ans;
    return 0;
}
