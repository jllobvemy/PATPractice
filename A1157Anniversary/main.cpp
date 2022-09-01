#include <bits/stdc++.h>
// Accepted!
using namespace std;
bool cmp(string& a, string& b) {
    return a.substr(6, 8) < b.substr(6, 8);
}

int main() {
    int N, M;
    cin >> N;
    vector<string> s1(N);
    for (int i = 0; i < N; ++i) {
        cin >> s1[i];
    }
    sort(s1.begin(), s1.end());
    cin >> M;
    vector<string> s2(M);
    for (int i = 0; i < M; ++i) {
        cin >> s2[i];
    }
    sort(s2.begin(), s2.end());
    vector<string> ans;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(ans));
    cout << ans.size() << endl;
    string* order;
    if (ans.empty()) {
        sort(s2.begin(), s2.end(), cmp);
        order = &s2[0];
    }
    else {
        sort(s1.begin(), s1.end(), cmp);
        order = &s1[0];
    }
    cout << *order;
    return 0;
}
