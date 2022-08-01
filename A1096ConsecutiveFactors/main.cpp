#include <bits/stdc++.h>
// Accepted!
using namespace std;
int main() {
    int num;
    cin >> num;
    if (num == 2) {
        cout << 1 << endl << 2;
        return 0;
    }
    int last = sqrt(num) + 1;
    int maxlen = 0;
    int lastelem = -1;
    for (int i = 2; i < last; ++i) {
        if (num % i == 0) {
            if (lastelem == -1) {
                lastelem = i;
                maxlen = 1;
            }
            int j = i + 1;
            long long a = i;
            while (true) {
                a *= j;
                if (num % a != 0) break;
                if (maxlen < j - i + 1) {
                    maxlen = j - i + 1;
                    lastelem = j;
                }
                j++;
            }
        }
    }
    if (lastelem == -1) {
        cout << 1 << endl << num;
    }
    else if (maxlen > 1){
        bool first = true;
        cout << maxlen << endl;
        do {
            if (first) {
                cout << lastelem - maxlen + 1;
                first = false;
            }
            else {
                cout << "*" << lastelem - maxlen + 1;
            }
        } while(--maxlen);
    } else {
        cout << 1 << endl << lastelem;
    }
    return 0;
}
