#include <bits/stdc++.h>
// Accepted!
using namespace std;
bool isPrime(long long num) {
    if (num == 2) return true;
    if (num <= 1 || num % 2 == 0) return false;
    long long last = sqrt(num) + 1;
    for (int i = 3; i < last; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int N, M;
    string num;
    cin >> N >> M >> num;
    char fmt[100];
    char buf[100];
    for (int i = 0; i < num.size() - M + 1; ++i) {
        long long n = stoll(num.substr(i, M));
        if (isPrime(n)) {
            sprintf(fmt, "%%0%dd", M);
            sprintf(buf, fmt, n);
            cout << buf << endl;
            return 0;
        }
    }
    cout << 404 << endl;
    return 0;
}
