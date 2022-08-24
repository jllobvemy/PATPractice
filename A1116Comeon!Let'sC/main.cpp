#include <bits/stdc++.h>
// Accepted!
using namespace std;

bool isPrime(int n) {
    if (n == 0 || n == 1) return false;
    if (n == 2 || n == 3) return true;
    int total = sqrt(n) + 1;
    for (int i = 2; i < total; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
const char* Award[] = {"Mystery Award", "Minion", "Chocolate"};
map<int, int> mapAward;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int tmp;
        cin >> tmp;
        if (i == 1) {
            mapAward[tmp] = 0;
        }
        else if (isPrime(i)) {
            mapAward[tmp] = 1;
        }
        else mapAward[tmp] = 2;
    }
    int K;
    cin >> K;
    set<int> checked;
    char buf[100];
    for (int i = 0; i < K; ++i) {
        int query;
        cin >> query;
        if (mapAward.find(query) == mapAward.end()) {
            sprintf(buf, "%04d: Are you kidding?\n", query);
            cout << buf;
        }
        else if (checked.find(query) == checked.end()) {
            sprintf(buf, "%04d: %s\n", query, Award[mapAward[query]]);
            cout << buf;
            checked.insert(query);
        }
        else {
            sprintf(buf, "%04d: Checked\n", query);
            cout << buf;
        }
    }
    return 0;
}
