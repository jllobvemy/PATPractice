#include <bits/stdc++.h>
// Not complete.
using namespace std;
int N, M, K, Q;
struct Time {
    int min = 8, sec = 0;
    Time& operator+=(int a) {
        sec += a;
        int m = sec / 60;
        sec %= 60;
        min += m;
        return *this;
    }
};
vector<vector<int>> Queue;

template<typename T>
vector<T> min_elements(T begin, T end) {
    auto mine = min_element(begin, end);
    vector<T> ret;
    for (auto i = begin; i != end; i++) {
        if (*i == *mine) ret.push_back(i);
    }
    return ret;
}


int main() {
    cin >> N >> M >> K >> Q;
    Queue.resize(N);
    for (auto &q: Queue) {
        q.resize(M);
    }
    for (int i = 0; i < M * N; ++i) {
        cin >> Queue[i / M][i % N];
    }
    vector<Time> curtTime(N);
    map<int, Time> Query;
    for (int i = 0; i < K - N; ++i) {
        auto mine = min_elements(Queue[0].begin(), Queue[0].end());
        for (auto e: mine) {
            Queue[0].erase(e);
        }
        for_each(Queue[0].begin(), Queue[0].end(), [&mine](int& elem) {
            elem -= *mine[0];
        });

    }




    return 0;
}
