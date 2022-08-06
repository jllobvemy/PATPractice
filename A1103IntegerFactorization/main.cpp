#include <bits/stdc++.h>
// Not Ac. 22/30
using namespace std;
vector<int> powtree;
bool findanswer = false;
int N, K, P;

void FindFac(vector<int>& ans, int num, int powindex, int sum = 0) {
    if (ans.size() >= K) return;
    if (powindex >= powtree.size()) return;
    if (findanswer) return;
    if (sum < num) {
        while (sum < num) {
            sum += powtree[powindex];
            ans.push_back(powtree[powindex]);
            if (sum == num && ans.size() == K) {
                findanswer = true;
                return;
            }
        }
        while (sum > 0) {
            if (findanswer) break;
            sum -= powtree[powindex];
            ans.pop_back();
            FindFac(ans, num, powindex + 1, sum);
        }
    }
}

int main() {
    cin >> N >> K >> P;
    int end = pow(N, 1.0 / P);
    for (int i = end; i > 0; --i) {
        int current = pow(i, P);
        powtree.push_back(current);
    }
    vector<int> ans;
    vector<vector<int>> res;
    for (int i = 0; i < powtree.size(); i++) {
        ans.clear();
        FindFac(ans, N, i, 0);
        if (findanswer) {
            res.push_back(ans);
            findanswer = false;
        }
    }
    if (res.empty()) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (auto& r: res) {
        auto fun = [](vector<int>& x){
            for (auto &e: x) {
                e = pow(e, 1.0 / P);
            }
        };
        fun(r);
    }
    int max = -1;
    for (const auto& v: res) {
        int sum;
        sum = accumulate(v.begin(), v.end(), 0);
        if (sum > max) {
            ans = v;
            max = sum;
        }
        if (sum == max) {
            auto judge = [](const vector<int>& a, const vector<int>& b){
                for (int i = 0; i < a.size(); ++i) {
                    if (a[i] > b[i]) {
                        return true;
                    }
                    else if (a[i] < b[i]){
                        return false;
                    }
                }
            };
            if (judge(ans, v)) {
                ans = v;
            }
        }
    }
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
