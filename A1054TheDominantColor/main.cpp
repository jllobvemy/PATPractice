#include <bits/stdc++.h>
// Accepted!
using namespace std;
int main() {
    int N, M;
    map<int, int> colors;
    cin >> N >> M;
    int sum = N * M;
    for (int i = 0; i < sum; ++i) {
        int tmp;
        cin >> tmp;
        if (colors.find(tmp) == colors.end()) colors[tmp] = 1;
        else colors[tmp]++;
    }
    int max = -1;
    int ans = -1;
    for (const auto& e: colors) {
        if (e.second > max) {
            max = e.second;
            ans = e.first;
        }
    }
    cout << ans << endl;
    return 0;
}
