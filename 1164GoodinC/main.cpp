#include <bits/stdc++.h>
// Accepted!
using namespace std;
char LETTERS[26][7][5];

void PrintLetter(vector<string>& vs) {
    bool firstLine = true;
    for (auto& s: vs) {
        if (firstLine) firstLine = false;
        else cout << '\n';
        for (int i = 0; i < 7; ++i) {
            int cnt = 0;
            for (auto c: s) {
                if (cnt != s.size() && cnt != 0) cout << ' ';
                cnt++;
                for (int j = 0; j < 5; ++j) {
                    cout << LETTERS[c - 'A'][i][j];
                }
            }
            cout << '\n';
        }
    }
}

int main() {
    for (char i = 'A'; i <= 'Z'; ++i) {
        for (int j = 0; j < 7; ++j) {
            for (int k = 0; k < 5; ++k) {
                cin >> LETTERS[i - 'A'][j][k];
            }
        }
    }
    cin.get();
    string s;
    getline(cin, s);
    regex base(R"ab([A-Z]+)ab");
    auto Begin = s.cbegin();
    vector<string> vs;
    smatch res;
    while (regex_search(Begin, s.cend(), res, base)) {
        vs.push_back(res[0]);
        Begin = res.suffix().first;
    }
    PrintLetter(vs);
    return 0;
}
