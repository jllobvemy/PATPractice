#include <bits/stdc++.h>
// Accepted!
using namespace std;
long long answer = 0;
string PAT;

int main() {
    cin >> PAT;
    long long PNum = 0, ANum = 0, PANum = 0;
    for (char it : PAT) {
        if (it == 'P') {
            PNum++;
        }
        else if (it == 'A' && PNum > 0) {
            ANum++;
            PANum += PNum;
        } else if (PANum > 0){
            answer += PANum;
            answer %= 1000000007;
        }
    }
    cout << answer;
    return 0;
}
