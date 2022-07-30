#include <bits/stdc++.h>
// Accepted!
using namespace std;
int N;
int main() {
    scanf("%d", &N);
    // notice that we need long double here.
    long double ans = 0.0;
    for (int i = 0; i < N; ++i) {
        double tmp;
        scanf("%lf", &tmp);
        ans += tmp * (N - i) * (i + 1);
    }
    printf("%.2Lf", ans);
    return 0;
}
