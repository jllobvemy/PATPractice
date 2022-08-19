#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    int nums1[3], nums2[3];
    string s1, s2;
    cin >> s1;
    cin >> s2;
    stringstream ss;
    ss << s1;
    string tmp;
    int i = 0;
    while (getline(ss, tmp, '.')) {
        nums1[i++] = stoi(tmp);
    }
    ss.clear();
    ss << s2;
    i = 0;
    while (getline(ss, tmp, '.')) {
        nums2[i++] = stoi(tmp);
    }
    for (int j = 2; j >= 0; --j) {
        nums1[j] += nums2[j];
    }
    int carry = 0;
    carry = nums1[2] / 29;
    nums1[2] %= 29;
    nums1[1] += carry;
    carry = nums1[1] / 17;
    nums1[1] %= 17;
    nums1[0] += carry;
    bool first = true;
    for (int j : nums1) {
        if (first) {
            first = false;
            cout << j;
        }
        else cout << "." << j;
    }
    return 0;
}
