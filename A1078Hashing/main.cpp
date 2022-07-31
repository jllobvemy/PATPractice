#include <bits/stdc++.h>
// Accepted!
using namespace std;

bool is_prime(int x) {
    if (x == 2) return true;
    if (x == 0 || x == 1 || x % 2 == 0) return false;
    int last = sqrt(x) + 1;
    for (int i = 3; i < last; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int MSize, N;
    cin >> MSize >> N;
    while (!is_prime(MSize)) {
        MSize++;
    }
    vector<int> table(MSize, -1);
    bool first = true;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        int index = tmp % MSize;
        const int cindex = index;
        int rate = 1;
        int looptimes = 0;
        while (table[index] != -1) {
            looptimes++;
            index = cindex;
            index += rate * rate;
            index %= MSize;
            if (looptimes >= MSize) {
                index = -1;
                break;
            }
            rate++;
        }
        if (index != -1) table[index] = tmp;
        if (first){
            if (index == -1) cout << "-";
            else cout << index;
            first = false;
        }
        else {
            if (index == -1) cout << " -";
            else cout << " " << index;
        }
    }
    cout << endl;
    return 0;
}
