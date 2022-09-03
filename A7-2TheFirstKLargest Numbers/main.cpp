#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
//    freopen("input.txt", "r", stdin);
//    auto start = chrono::steady_clock::now();
    int N, K;
    cin >> N >> K;
    int size = N > K? K: N;
    vector<int> vec(size);
    for (int i = 0; i < size; ++i) {
        cin >> vec[i];
    }
    make_heap(vec.begin(), vec.end(), greater<>());
    int last = N - K;
    for (int i = 0; i < last ; ++i) {
        pop_heap(vec.begin(), vec.end(), greater<>());
        int tmp;
        cin >> tmp;
        if (tmp > vec.back()) vec.back() = tmp;
        push_heap(vec.begin(), vec.end(), greater<>());
    }
    sort(vec.begin(), vec.end(), greater<>());
    bool first = true;
    for (int i = 0; i < size; ++i) {
        if (first) first = false;
        else cout << " ";
        cout << vec[i];
    }
    cout << endl;
//    auto endtime = chrono::steady_clock::now();
//    cout << chrono::duration_cast<chrono::milliseconds>(endtime - start).count() << "ms" <<endl;

    return 0;
}
