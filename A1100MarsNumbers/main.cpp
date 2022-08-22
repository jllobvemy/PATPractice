#include <bits/stdc++.h>
// Accepted!
using namespace std;
const char* ones[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug",
                      "sep", "oct", "nov", "dec"};
const char* tens[] = { "", "tam", "hel", "maa", "huh", "tou", "kes",
                       "hei", "elo", "syy", "lok", "mer", "jou"};

int MarToNum(vector<string>& s) {
    if (s.size() > 1) {
        int tenposi = find(begin(tens), end(tens), s[0]) - begin(tens);
        int oneposi = find(begin(ones), end(ones), s[1]) - begin(ones);
        return tenposi * 13 + oneposi;
    }
    else if(s.size() == 1) {
        int oneposi = find(begin(ones), end(ones), s[0]) - begin(ones);
        if (oneposi != 13)
            return oneposi;
        int tenposi = find(begin(tens), end(tens), s[0]) - begin(tens);
        return tenposi * 13;
    }
    else exit(1);
}

string NumToMar(int n) {
    string ret;
    int ten = n / 13;
    int one = n % 13;
    if (one != 0 && n > 13) {
        ret += tens[ten];
        ret += " ";
        ret += ones[one];
    }
    else if (one == 0 && n >= 13) {
        ret += tens[ten];
    }
    else {
        ret += (ones[one]);
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    cin.get();
    for (int i = 0; i < N; ++i) {
        string tmp;
        getline(cin, tmp);
        if (isdigit(tmp[0])) {
            cout << NumToMar(stoi(tmp)) << endl;
        }
        else {
            stringstream ss(tmp);
            vector<string> param;
            while (getline(ss, tmp, ' ')) {
                param.emplace_back(tmp);
            }
            cout << MarToNum(param) << endl;
        }
    }

    return 0;
}
