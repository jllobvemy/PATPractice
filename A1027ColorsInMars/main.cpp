#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr char NUMMAP[] = {'0', '1', '2', '3', '4', '5',
                           '6', '7', '8', '9', 'A', 'B', 'C'};
vector<int> TransForm(int val, int base) {
    vector<int> ret;
    while (val) {
        ret.push_back(val % base);
        val /= base;
    }
    while (ret.size() < 2) {
        ret.push_back(0);
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    cout << "#";
    for (int i = 0; i < 3; ++i) {
        int tmp;
        cin >> tmp;
        auto ret = TransForm(tmp, 13);
        for (auto& j: ret) {
            cout << NUMMAP[j];
        }
    }
    return 0;
}
