#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    regex base(R"re([+-]?(0*([0-9]+))\.?([0-9]{1,2})?)re");
    char buf[100];
    int N;
    cin >> N;
    double sum = 0;
    int cnt = 0;
    string s;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        smatch ss;
        bool res;
        try {
            res = regex_match(s, ss, base);
        }
        catch (...) {
            return 1;
        }
        if (res) {
            double tmp = stod(s);
            if (abs(tmp) > 1000) {
                sprintf(buf, "ERROR: %s is not a legal number\n", s.c_str());
                cout << buf;
            }
            else {
                sum += tmp;
                cnt++;
            }
        }
        else {
            sprintf(buf, "ERROR: %s is not a legal number\n", s.c_str());
            cout << buf;
        }
    }
    if (cnt == 0) {
        cout << "The average of 0 numbers is Undefined\n";
    }
    else if (cnt == 1){
        double tmp = sum / cnt;
        sprintf(buf, "The average of %d number is %.2f\n", cnt, tmp);
        cout << buf;
    } else {
        double tmp = sum / cnt;
        sprintf(buf, "The average of %d numbers is %.2f\n", cnt, tmp);
        cout << buf;
    }
    return 0;
}
