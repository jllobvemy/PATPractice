#include <bits/stdc++.h>
// Accepted! LCS
using namespace std;

int main() {
    int NN;
    cin >> NN;
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
    }
    int M;
    cin >> M;
    vector<int> b(M + 1);
    for (int i = 1; i <= M; ++i) {
        cin >> b[i];
    }
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            int m = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i] == b[j]) dp[i][j] = m + 1;
            else dp[i][j] = m;
        }
    }
    cout << dp[N][M];
    return 0;
}
