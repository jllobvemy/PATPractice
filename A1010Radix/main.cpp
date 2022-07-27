#include <bits/stdc++.h>
// Accepted!
using namespace std;
int char2num(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'z') return c - 'a' + 10;
    throw runtime_error("");
}
long long any2ten(const string& s, long long radix) {
    long long res = 0;
    for (char it : s) {
        auto tmp = res;
        res *= radix;
        if (res / radix != tmp) return -1;
        res += char2num(it);
        if (res < 0) return -1;
    }
    return res;
}

string N1, N2;
int tag, radix;

int main() {
    cin >> N1 >> N2 >> tag >> radix;
    long long num;
    string& unknown = N2;
    if (tag == 1) {
        num = any2ten(N1, radix);
    }
    else {
        num = any2ten(N2, radix);
        unknown = N1;
    }
    auto i = *max_element(unknown.begin(), unknown.end());
    long long   lower = char2num(i) + 1, // 注意此处的上下界是必须的，否则可能出现不符合实际情况的答案
                upper = max(lower, num);
    long long mid;
    bool no_answer = true;
    while (lower <= upper) {
        mid = (lower + upper) / 2;
        long long value = any2ten(unknown, mid);
        if (value == num) {
            no_answer = false;
            break;
        }
        if (value > num || value < 0) {
            upper = mid - 1;
        }
        else {
            lower = mid + 1;
        }
    }
    if (no_answer) cout << "Impossible";
    else cout << mid;
    return 0;
}
