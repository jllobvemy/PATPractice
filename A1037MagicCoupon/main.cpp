#include <bits/stdc++.h>
// Accepted!
using namespace std;
int NC, NP;

multiset<int, greater<>> Cp; // Coupon positive
multiset<int> Cn; // Coupon negative
multiset<int, greater<>> Pp; // Product positive
multiset<int> Pn; // Product negative

int main() {
    int tmp;
    int res = 0;
    cin >> NC;
    for (int i = 0; i < NC; ++i) {
        cin >> tmp;
        if (tmp > 0)
            Cp.insert(tmp);
        else
            Cn.insert(tmp);
    }
    cin >> NP;
    for (int i = 0; i < NP; ++i) {
        cin >> tmp;
        if (tmp > 0)
            Pp.insert(tmp);
        else
            Pn.insert(tmp);
    }
    auto itc = Cp.begin();
    auto itp = Pp.begin();
    while (itc != Cp.end() && itp != Pp.end()) {
        res += *itc * *itp;
        itc++;
        itp++;
    }
    itc = Cn.begin();
    itp = Pn.begin();
    while (itc != Cn.end() && itp != Pn.end()) {
        res += *itc * *itp;
        itc++;
        itp++;
    }
    cout << res;
    return 0;
}
