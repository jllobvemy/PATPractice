#include <bits/stdc++.h>
// Accepted!
using namespace std;
bool cmp(int a, int b) {
    if (a <= 0 && b > 0) return false;
    if (a > 0 && b <= 0) return true;
    return a < b;
}
int main() {
    int N;
    cin >> N;
    vector<int> vec(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }
    vec[N] = -1; // 哨兵
    sort(vec.begin(), vec.end(), cmp);
    if (vec[0] != 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = 1; i < N + 1; ++i) {
        if ((vec[i] == vec[i - 1] + 1) || (vec[i] == vec[i - 1])) {
            continue;
        }
        cout << vec[i - 1] + 1 << endl;
        return 0;
    }


    return 0;
}
