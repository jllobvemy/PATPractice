#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    int N;
    cin >> N;
    priority_queue<double, vector<double>, greater<>> q;
    int maxelem = -1;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        q.push(tmp);
        if (tmp > maxelem) maxelem = tmp;
    }
    double sum = 0;
    sum += q.top();
    q.pop();
    sum += q.top();
    q.pop();
    sum /= 2;
    while (!q.empty()) {
        sum = (sum + q.top()) / 2;
        q.pop();
    }
    int res = floor(sum);
    if (res > maxelem) return 1;
    cout << res << endl;
    return 0;
}
