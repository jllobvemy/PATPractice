#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr string_view DTS[] = {"zero", "one", "two",
                             "three", "four", "five", "six",
                             "seven", "eight", "nine"};

int main() {
    long long ans = 0;
    char c;
    while ((c = cin.get()) != '\n') {
        ans += c - '0';
    }
    char sans[200];
    sprintf(sans, "%lld", ans);
    bool first = true;
    for (auto i = 0; sans[i] != '\0'; i++) {
        if (first) {
            first = false;
            cout << DTS[sans[i] - '0'];
        }
        else cout << " " << DTS[sans[i] - '0'];
    }
    return 0;
}
