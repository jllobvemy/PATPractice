#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        int a, b, product;
        a = stoi(s.substr(0, s.size() / 2));
        b = stoi(s.substr(s.size() / 2, s.size()));
        product = stoi(s);
        if (a * b == 0) {
            cout << "No" << endl;
            continue;
        }
        cout << (product % (a * b) == 0? "Yes": "No") << endl;
    }
    return 0;
}
