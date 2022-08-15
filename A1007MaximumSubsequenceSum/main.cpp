#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> V(N, 0);
    bool allNeg = true;
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
        if (V[i] >= 0) allNeg = false;
    }
    if (allNeg) {
        cout << 0 << " " << V[0] << " " << V[N - 1] << endl;
        return 0;
    }
    vector<tuple<int, int>> sum(N); // sum, min, max
    sum[0] = make_tuple(V[0], V[0]);
    int maxindex = 0;
    int curtMax = -1;
    for (int i = 1; i < N; ++i) {
        int sumbefore = get<0>(sum[i - 1]) + V[i];
        if (sumbefore > V[i]) {
            sum[i] = make_tuple(sumbefore, get<1>(sum[i - 1]));
        }
        else {
            sum[i] = make_tuple(V[i], V[i]);
        }
        if (curtMax < get<0>(sum[i])) {
            curtMax = get<0>(sum[i]);
            maxindex = i;
        }
    }
    cout <<  get<0>(sum[maxindex]) << " " << get<1>(sum[maxindex]) << " " << V[maxindex];
    return 0;
}
