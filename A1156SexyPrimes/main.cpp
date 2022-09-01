#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAX = 1000000001;
bool isPrime(int n) {
    if (n <= 1 || n % 2 == 0) return false;
    if (n == 2) return true;
    int ending = sqrt(n ) + 1;
    for (int i = 3; i < ending; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}
int Sexy(int N) {
    if (isPrime(N)) {
        if (isPrime(N - 6)) {
            return N - 6;
        }
        if (isPrime(N + 6)) {
            return N + 6;
        }
    }
    return -1;
}

bool isSexy(int N) {
    if (isPrime(N)) {
        if (isPrime(N - 6)) {
            return true;
        }
        if (isPrime(N + 6)) {
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    int res = Sexy(N);
    if (res > 0) {
        cout << "Yes" << endl << res;
        return 0;
    }
    for (int i = N + 1; i < MAX; ++i) {
        res = isSexy(i);
        if (res) {
            cout << "No" << endl << i;
            return 0;
        }
    }
    return 0;
}
