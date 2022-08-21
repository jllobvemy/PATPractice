#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> s;
    s.reserve(N);
    getchar();
    for (int i = 0; i < N; ++i) {
        string tmp;
        getline(cin, tmp);
        std::reverse(tmp.begin(), tmp.end());
        s.push_back(std::move(tmp));
    }
    int cnt = 0;
    string commonStr;
    for (int i = 0; i < s[0].size(); ++i) {
        char curtC = s[0][i];
        bool hasAdd = false;
        for (int j = 0; j < s.size(); ++j) {
            if (i >= s[j].size()) goto end;
            if (s[j][i] == curtC && commonStr == s[j].substr(0, commonStr.size())) {
                if (!hasAdd) {
                    commonStr.push_back(curtC);
                    hasAdd = true;
                }
            }
            else {
                commonStr.pop_back();
                goto end;
            }
        }
    }
    end:;
    if (commonStr.empty()) {
        cout << "nai" << endl;
        return 0;
    }
    std::reverse(commonStr.begin(), commonStr.end());
    cout << commonStr;
    return 0;
}
