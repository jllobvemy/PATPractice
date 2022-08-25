#include <bits/stdc++.h>
// 15/20
using namespace std;

int main() {
    int M, N, S;
    cin >> M >> N >> S;
    unordered_set<string> winner;
    vector<string> ans;
    int supply = 0;
    for (int i = 1; i <= M; ++i) {
        string person;
        cin >> person;
        int offset = 0;
        if (supply || i == S || (i > S && (i - S) % N == 0)) {
            if (supply > 0 && !(i == S || (i > S && (i - S) % N == 0))) supply--;
            while (winner.find(person) != winner.end()) {
                offset++;
                if (offset % N == 0) supply++;
                if (i + offset > M) break;
                cin >> person;
            }
            if (winner.find(person) == winner.end()) {
                winner.insert(person);
                ans.push_back(person);
            }
        }
        i += offset;
    }
    if (winner.empty()) {
        cout << "Keep going..." << endl;
    }
    for (auto i = ans.begin(); i != ans.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}
