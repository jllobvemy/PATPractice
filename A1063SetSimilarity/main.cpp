#include <bits/stdc++.h>
// Accepted!
using namespace std;

double Similarity(const vector<int>& a, const vector<int>& b) {
    auto ita = a.begin();
    auto itb = b.begin();
    size_t sum = a.size() + b.size();
    size_t acc = 0;
    while (true) {
        if (*ita == *itb) {
            acc++;
            ita++;
            itb++;
        }
        else if (*ita < *itb) {
            ita++;
        }
        else {
            itb++;
        }
        if (ita == a.end() || itb == b.end())
            break;
    }
    size_t distinct = sum - acc;
    return acc * 1.0 / distinct;
}

int main() {
    vector<vector<int>> numbers;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        vector<int> tmpv;
        int tmpnum;
        cin >> tmpnum;
        for (int j = 0; j < tmpnum; ++j) {
            int tmp;
            cin >> tmp;
            tmpv.push_back(tmp);
        }
        sort(tmpv.begin(), tmpv.end());
        auto vend = unique(tmpv.begin(), tmpv.end());
        numbers.emplace_back(tmpv.begin(), vend);
    }
    int qNum;
    cin >> qNum;
    char buf[10];
    for (int i = 0; i < qNum; ++i) {
        int a, b;
        cin >> a >> b;
        double res = Similarity(numbers[a - 1], numbers[b - 1]);
        sprintf(buf, "%.1f%%\n", res * 100);
        cout << buf;
    }
    return 0;
}
