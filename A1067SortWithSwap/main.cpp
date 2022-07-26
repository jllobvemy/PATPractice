#include <bits/stdc++.h>
// Accepted!
using namespace std;
array<int, 100020> v;
array<int, 100020> num2index;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        v[i] = tmp;
        num2index[tmp] = i;
    }
    int res = 0;
    int currentValue = 1;
    while (true) {
        if (v[0] == 0) {
            bool flag = true;
            for (; currentValue < N; ++currentValue) {
                if (v[currentValue] != currentValue) {
                    swap(v[0], v[currentValue]);
                    num2index[0] = currentValue;
                    num2index[v[0]] = 0;
                    res++;
                    flag = false;
                    break;
                }
            }
            if (flag) {
                goto end;
            }
        }
        int value0index = num2index[0];
        swap(v[value0index], v[num2index[value0index]]);
        num2index[0] = num2index[value0index];
        num2index[value0index] = value0index;
        res++;
    }
    end:;
    cout << res << endl;
    return 0;
}
