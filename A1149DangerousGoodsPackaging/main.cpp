#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<array<int, 2>> incompatible;
    incompatible.resize(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        incompatible[i][0] = a;
        incompatible[i][1] = b;
    }
    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        vector<int> vec(num);
        for (int j = 0; j <num; ++j) {
            cin >> vec[j];
        }
        sort(vec.begin(), vec.end());
        vector<int> ans;
        for (auto& a: incompatible) {
            ans.clear();
            set_intersection(a.begin(), a.end(), vec.begin(), vec.end(), back_inserter(ans));
            if (ans.size() == 2) {
                cout << "No" << endl;
                goto end;
            }
        }
        cout << "Yes" << endl;
        end:;
    }

    return 0;
}
