#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    int N, E = 0;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<>());
    while (E < N && A[E] > E + 1) E++;
    cout << E;
    return 0;
}
