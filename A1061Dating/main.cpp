#include <bits/stdc++.h>
// Accepted!
using namespace std;
array<string, 7> Weekday {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    array<string, 4> strs;
    for (int i = 0; i < 4; i++) {
        cin >> strs[i];
    }
    int len = min(strs[0].size(), strs[1].size());
    int day = -1, hh = -1, mm = -1;
    bool first = true;
    for (int i = 0; i < len; ++i) {
        if (first) {
            if (strs[0][i] >= 'A' && strs[0][i] <= 'G') {
                if (strs[0][i] == strs[1][i]) {
                    day = strs[0][i] - 'A';
                    first = false;
                    continue;
                }
            }
        }
        else {
            char c = strs[0][i];
            if (isalnum(c)) {
                if (strs[0][i] == strs[1][i]) {
                    if (c >= '0' && c <= '9') {
                        hh = c - '0';
                        break;
                    }
                    else if (c >= 'A' && c <= 'N') {
                        hh = strs[0][i] - 'A' + 10;
                        break;
                    }
                }
            }
        }
    }
    len = min(strs[2].size(), strs[3].size());
    for (int i = 0; i < len; ++i) {
        if (isalpha(strs[2][i])) {
            if (strs[2][i] == strs[3][i]) {
                mm = i;
                break;
            }
        }
    }
//    if (day == -1 || mm == -1 || hh == -1 || day > 7 || mm > 59 || hh > 23) return 2;
//    if (day > 7) return 1;
    char buf[50];
    sprintf(buf, "%s %02d:%02d", Weekday[day].c_str(), hh, mm);
    cout << buf;
    return 0;
}
