#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int n = s.length() + 2;
    int n1 = 3, n2 = 0;
    n1 = n / 3;
    n2 = n - n1 * 2;
    int space = n2 - 2;
    for (int i = 0; i < n1 - 1; ++i) {
        int last = s.length() - i - 1;
        cout << s[i];
        for (int j = 0; j < space; ++j) {
            cout << " ";
        }
        cout << s[last];
        cout << endl;
    }
    for (int i = 0; i < n2; ++i) {
        int begin = n1 + i - 1;
        cout << s[begin];
    }
    return 0;
}
