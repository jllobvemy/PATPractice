#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    int num;
    cin >> num;
    long long res = 0;
    int a = 1;
    while (num / a) {
        int now = num / a % 10, left = num / (a * 10), right = num % a;
        if (now == 0) {
            res += (left * a);
        }
        else if (now == 1) {
            res += (left * a) + right + 1;
        }
        else {
            res += (left + 1) * a;
        }
        a *= 10;
    }
    cout << res;

    return 0;
}
