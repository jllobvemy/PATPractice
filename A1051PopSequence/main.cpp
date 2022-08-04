#include <bits/stdc++.h>
using namespace std;
#define FAIL return false;
stack<int> fixs;
int M, N, K;
bool Check(const vector<int>& c) {
    stack<int> s;
    stack<int> maxs = fixs;
    for (auto v: c) {
        if (s.empty()) {
            do {
                if (maxs.empty()) {
                    FAIL
                }
                s.push(maxs.top());
                if (s.size() > M) {
                    FAIL
                }
                maxs.pop();
            } while (s.top() < v);
        }
        if (s.top() == v) {
            s.pop();
            continue;
        }
        if (s.top() < v) {
            while (s.top() < v) {
                if (maxs.empty()) {
                    FAIL
                }
                s.push(maxs.top());
                if (s.size() > M) {
                    FAIL
                }
                maxs.pop();
            }
        }
        if (s.top() == v) {
            s.pop();
        }
        else {
            FAIL
        }
    }
    return true;
}


int main() {
    cin >> M >> N >> K;
    stack<int> s;
    for (int i = N; i > 0; --i) {
        fixs.push(i);
    }
    for (int i = 0; i < K; i++) {
        vector<int> tmp;
        for (int j = 0; j < N; ++j) {
            int v;
            cin >> v;
            tmp.push_back(v);
        }
        if (Check(tmp)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
