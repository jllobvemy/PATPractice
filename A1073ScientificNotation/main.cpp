#include <bits/stdc++.h>
// Accepted!
using namespace std;

struct Decimal {
    string data;
    int flag = 1;
    int pointPosi = INT_MAX;
    Decimal(const string& s) {
        if (s[0] == '-') flag = -1;
        else flag = 1;
        smatch res;
        regex base_regex(R"b(([+-])([1-9])\.([0-9]+)E([+-][0-9]+))b");
        regex_match(s, res, base_regex);
        if (res.size() != 5) exit(1);
        flag = res[1] == "-"? -1: 1;
        string tmp = res[2];
        tmp += res[3];
        data = tmp;
        pointPosi = stoi(res[4]);
    }
    string to_string() {
        stringstream ss;
        if (flag == -1) ss << '-';
        if (pointPosi >= 0) {
            int i = 0;
            for (i = 0; i <= pointPosi; ++i) {
                if (i >= data.size())
                    ss << '0';
                else ss << data[i];
            }
            if (i < data.size())
                ss << '.';
            for (; i < data.length(); i++) {
                ss << data[i];
            }
        }
        else {
            ss << "0.";
            for (int i = 1; i < -pointPosi; ++i) {
                ss << '0';
            }
            ss << data;
        }
        return ss.str();
    }
};

int main() {
    string s;
    cin >> s;
    Decimal d(s);
    cout << d.to_string();
    return 0;
}
