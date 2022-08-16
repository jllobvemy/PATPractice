#include <bits/stdc++.h>
// Accepted!
using namespace std;
const char M[] = {'W', 'T', 'L'};

int main() {
    array<double, 3> Bets {};
    double acc = 1;
    array<char, 3> ans {};
    for (int i = 0; i < 3; ++i) {
        cin >> Bets[0] >> Bets[1] >> Bets[2];
        ans[i] = max_element(Bets.begin(), Bets.end()) - Bets.begin();
        acc *= Bets[ans[i]];
    }
    acc *= 0.65;
    if (acc > 0) acc--;
    acc *= 2;
    char buf[50];
    sprintf(buf, "%c %c %c %.2f", M[ans[0]], M[ans[1]], M[ans[2]], acc);
    cout << buf;
    return 0;
}
