#include <bits/stdc++.h>
// Accepted!
using namespace std;
string Describe(const string& s) {
    stringstream ss;
    regex base(R"ab((\d)\1*)ab");
    smatch res;
    auto Begin = s.begin();
    while(regex_search(Begin, s.end(), res, base)) {
        ss << res[1].str() << res[0].str().length();
        Begin = res.suffix().first;
    }
    return ss.str();
}
int main() {
    string D;
    int N;
    cin >> D >> N;
    while (--N) {
        D = Describe(D);
    }
    cout << D;
    return 0;
}

