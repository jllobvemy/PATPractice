#include <bits/stdc++.h>
// Accepted!
using namespace std;

struct Digit {
    string num;
    bool operator<(const Digit& b) const {
//        stringstream tmp;
//        tmp << num << b.num;
//        int first;
//        tmp >> first;
//        tmp.clear();
//        tmp << b.num << num;
//        int second;
//        tmp >> second;
//        return first < second;
        return num + b.num < b.num + num;
    }
};

int N;
multiset<Digit> digits;


int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        Digit tmp;
        cin >> tmp.num;
        digits.insert(tmp);
    }
    bool firstnum = true;
    for (auto it = digits.begin(); it != digits.end(); it++) {
        while (firstnum) {
            if (it == digits.end()) {
                cout << 0 << endl;
                return 0;
            }
            for (auto c: it->num) {
                if (c != '0' || !firstnum) {
                    cout << c;
                    firstnum = false;
                }
            }
            it++;
        }
        if (it == digits.end()) break;
        cout << it->num;
    }
    cout << endl;
    return 0;
}
