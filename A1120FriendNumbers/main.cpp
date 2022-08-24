#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> ans;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        int sum = 0;
        while (tmp) {
            sum += tmp % 10;
            tmp /= 10;
        }
        ans.insert(sum);
    }
    cout << ans.size() << endl;
    bool first = true;
    for (auto i: ans) {
        if (first) {
            first = false;
            cout << i;
        }
        else {
            cout << " " << i;
        }
    }
    return 0;
}
