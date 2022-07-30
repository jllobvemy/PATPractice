#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> nums;
vector<int> ans;
multiset<int> rightminset;

int main() {
    cin >> N;
    nums.reserve(N);
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
        rightminset.insert(tmp);
    }
    int leftmax = 0;
    for (auto it = nums.begin(); it != nums.end(); it++) {
        if (*it > leftmax)
        {
            leftmax = *it;
            if (*rightminset.begin() >= *it) {
                ans.push_back(*it);
            }
        }
        rightminset.erase(*it);
    }
    cout << ans.size() << endl;
    bool first = true;
    for (auto i: ans) {
        if (first) {
            cout << i;
            first = false;
        }
        else {
            cout << " " << i;
        }
    }
    cout << endl;
    return 0;
}
