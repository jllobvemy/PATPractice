#include <bits/stdc++.h>
// Not Ac. 17/25
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    cin.get();
    stringstream buf1;
    stringstream buf2;
    char tmp;
    bool finddot = false;
    int dotplace1 = 0;
    int current1 = 0;
    bool begin = true;
    while (cin.get(tmp) && tmp != ' ') {
        if (begin) {
            begin = false;
            if (tmp == '0') {
                cin.get();
                finddot = true;
                continue;
            }
        }
        if (!finddot) {
            if (tmp == '.') {
                finddot = true;
                dotplace1--;
            }
            dotplace1++;
        }
        current1++;
        if (tmp != '.' && current1 <= N)
            buf1 << tmp;
    }
    string s1 = buf1.str();
    int dotplace2 = 0;
    finddot = false;
    int current2 = 0;
    begin = true;
    while (cin.get(tmp) && tmp != '\n') {
        if (begin) {
//            while (tmp == '0' || tmp == '.') {
//                if (tmp == '.')
//                    finddot = true;
//                cin.get(tmp);
//            }
            if (tmp == '0') {
                cin.get();
                finddot = true;
                continue;
            }
            begin = false;
        }
        if (!finddot) {
            if (tmp == '.') {
                finddot = true;
                dotplace2--;
            }
            dotplace2++;
        }
        current2++;
        if (tmp != '.' && current2 <= N)
            buf2 << tmp;
    }
    string s2 = buf2.str();
    char buf[300];
    if (dotplace1 == dotplace2 && s1 == s2) {
//        if (dotplace1 != 0)
            sprintf(buf, "YES 0.%s*10^%d", s1.c_str(), dotplace1);
//        else
//            sprintf(buf, "YES 0.%s", s1.c_str());
        cout << buf;
    }
    else {
        sprintf(buf, "NO 0.%s*10^%d 0.%s*10^%d", s1.c_str(), dotplace1, s2.c_str(), dotplace2);
        cout << buf;
//        cout << "NO" << " 0." << s1;
//        if (dotplace1 != 0)
//            cout << "*10^" << dotplace1;
//        cout << " 0." << s2;
//        if (dotplace2 != 0) {
//            cout << "*10^" << dotplace2;
//        }
    }
    return 0;
}
