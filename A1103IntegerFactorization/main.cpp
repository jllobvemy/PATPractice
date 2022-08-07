#include <bits/stdc++.h>
// Accepted!
using namespace std;
vector<int> powtree;
vector<int> ans;
vector<int> tmp;
int anssum = 0;
int N, K, P;
auto depow = [](vector<int>& x){
    for (auto &e: x) {
        e = pow(e, 1.0 / P);
    }
};

void FindFac(int index, int sum) {
    if (tmp.size() > K || sum > N || index >= powtree.size()) return;
    if ((sum == N && tmp.size() != K) || (sum != N && tmp.size() == K)) return;
    if (sum == N && tmp.size() == K) {
        auto acctmp = tmp;
        depow(acctmp);
        int acc = accumulate(acctmp.begin(), acctmp.end(), 0);
        if (anssum < acc) {
            ans = tmp;
            anssum = acc;
        } else if (anssum == acc) {
            for (int i = 0; i < K; i++) {
                if (tmp[i] > ans[i]) {
                    ans = tmp;
                    break;
                }
                else if (tmp[i] < ans[i]){
                    break;
                }
            }
        }
    };
    tmp.push_back(powtree[index]);
    FindFac(index, sum + powtree[index]);
    tmp.pop_back();
    FindFac(index + 1, sum);
}

int main() {
    cin >> N >> K >> P;
    int end = pow(N, 1.0 / P);
    for (int i = end; i > 0; --i) {
        int current = pow(i, P);
        powtree.push_back(current);
    }
    FindFac(0, 0);
    if (ans.empty()) {
        cout << "Impossible" << endl;
        return 0;
    }
    depow(ans);
    cout << N << " =";
    bool first = true;
    for (auto &e: ans) {
        if (first) {
            first = false;
            cout << " " << e << "^" << P;
        }
        else {
            cout << " + " << e << "^" << P;
        }
    }
    return 0;
}
