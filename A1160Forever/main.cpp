#include <bits/stdc++.h>
// Accepted!
using namespace std;
bool isPrime(int a) {
    if (a == 1 || a == 0) return false;
    if (a == 2) return true;
    int n = sqrt(a) + 1;
    for (int i = 2; i <= n; ++i) {
        if (a % i == 0) return false;
    }
    return true;
}
int digitsSum(int d) {
    int ret = 0;
    while (d) {
        ret += d % 10;
        d /= 10;
    }
    return ret;
}

int main() {
    int N, K, m;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> K >> m;
        map<int, vector<int>> ans;
        cout << "Case " << i + 1 << endl;
        int startNum = round(pow(10, K - 1)) + 99;
        int endNum = round(pow(10, K));
        for (int j = startNum; j < endNum; j += 100) {
            if (digitsSum(j) == m) {
                int n = digitsSum(j + 1);
                int g = gcd(m, n);
                if (g > 2 && isPrime(g)) {
                    ans[n].push_back(j);
                }
            }
        }
        for (auto& [a, b]: ans) {
            for (auto e: b) {
                cout << a << " " << e << endl;
            }
        }
        if (ans.empty()) cout << "No Solution" << endl;
    }


    return 0;
}
