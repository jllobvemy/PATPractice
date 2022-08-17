#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr double ESP = 0.0001;
map<int, double> Poly;

int main() {
    map<int, double> ans;
    int N1;
    cin >> N1;
    for (int i = 0; i < N1; ++i) {
        int exp;
        double coe;
        cin >> exp >> coe;
        Poly[exp] = coe;
    }
    int N2;
    cin >> N2;
    for (int i = 0; i < N2; ++i) {
        int exp;
        double coe;
        cin >> exp >> coe;
        for (auto & it : Poly) {
            ans[it.first + exp] += coe * it.second;
        }
    }
    for (auto it = ans.begin(); it != ans.end(); it++) {
        if (abs(it->second) < ESP) ans.erase(it);
    }
    cout << ans.size();
    char tmp[100];
    for (auto i = ans.rbegin(); i != ans.rend(); i++) {
        sprintf(tmp, " %d %.1f", i->first, i->second);
        cout << tmp;
    }
    return 0;
}
