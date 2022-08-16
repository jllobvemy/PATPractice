#include <bits/stdc++.h>
// Accepted!
constexpr double ESP = 0.0000001;
using namespace std;

int main() {
    map<int, double> ans;
    int N1;
    cin >> N1;
    for (int i = 0; i < N1; ++i) {
        int tmp1;
        double tmp2;
        cin >> tmp1 >> tmp2;
        ans[tmp1] += tmp2;
        if (abs(ans[tmp1]) <= ESP) ans.erase(tmp1);
    }
    int N2;
    cin >> N2;
    for (int i = 0; i < N2; ++i) {
        int tmp1;
        double tmp2;
        cin >> tmp1 >> tmp2;
        ans[tmp1] += tmp2;
        if (abs(ans[tmp1]) <= ESP) ans.erase(tmp1);
    }
    cout << ans.size();
    char buf[50];
    for (auto it = ans.rbegin(); it != ans.rend(); it++) {
        sprintf(buf, " %d %.1f", it->first, it->second);
        cout << buf;
    }
    return 0;
}
