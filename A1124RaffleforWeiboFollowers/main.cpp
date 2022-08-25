#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    int M, N, S;
    cin >> M >> N >> S;
    unordered_set<string> winner;
    vector<string> ans;
    int curtPosi = 0;
    for (int i = 1; i <= M; ++i) {
        string person;
        cin >> person;
        if (i < S) continue;
        if (curtPosi % N == 0) {
            while (winner.find(person) != winner.end()) {
                cin >> person;
                i++;
                curtPosi = 0;
                if (i > M) break;
            }
            if (winner.find(person) == winner.end()) {
                ans.push_back(person);
                winner.insert(person);
            }
        }
        curtPosi++;
    }
    if (winner.empty()) {
        cout << "Keep going..." << endl;
    }
    for (auto i = ans.begin(); i != ans.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}
