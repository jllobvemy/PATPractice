#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int sum1 = accumulate(nums.begin(), nums.begin() + N / 2, 0);
    int sum2 = accumulate(nums.begin() + N / 2, nums.end(), 0);
    if (N % 2 == 0) {
        cout << 0 << " " << sum2 - sum1;
    }
    else {
        cout << 1 << " " << sum2 - sum1;
    }
    return 0;
}
