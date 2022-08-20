#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    long long a, b, c;
    int N;
    cin >> N;
    optional<bool> res;
    char buf[50];
    for (int i = 0; i < N; ++i) {
        scanf("%lld %lld %lld", &a, &b, &c); // 注意：只能用Scanf
        long long sum = a + b;
//        if ((a <= 0) ^ (b <= 0) || (a == 0 && b == 0)) {
//            res = sum > c;
//        }
        if (a > 0 && b > 0 && sum < 0) { // a > 0, b > 0
            res = true;
        }
        else if (a < 0 && b < 0 && sum >= 0) { // a < 0, b < 0
            res = false;
        }
        else if (sum > c){
            res = true;
        }
        else res = false;
        if (!res.has_value()) return 1;
        sprintf(buf, "Case #%d: %s\n", i + 1, res.value()? "true": "false");
        cout << buf;
    }
    return 0;
}
