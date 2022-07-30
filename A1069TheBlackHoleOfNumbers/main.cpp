#include <bits/stdc++.h>
// Accepted!
using namespace std;
void formatprint(int a, int b, int c) {
    char x[20];
    sprintf(x, "%04d - %04d = %04d", a, b, c);
    cout << x << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int num;
    cin >> num;
    char buf[10];
    sprintf(buf, "%04d", num);
    string a, b;
    a = b = buf;
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end());
    int inta = stoi(a), intb = stoi(b);
    int ans = inta - intb;
    formatprint(inta, intb, ans);
    if (ans == 0) return 0;
    while (ans != 6174) {
        char tmp[10];
        sprintf(tmp, "%04d", ans);
        a = tmp;
        b = tmp;
        std::sort(a.begin(), a.end(), greater<>());
        std::sort(b.begin(), b.end());
        inta = stoi(a);
        intb = stoi(b);
        ans = inta - intb;
        formatprint(inta, intb, ans);
    }
    return 0;
}
