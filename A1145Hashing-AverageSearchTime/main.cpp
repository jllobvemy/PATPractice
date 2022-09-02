#include <bits/stdc++.h>
// Accepted!
#define endl '\n'
using namespace std;
bool isPrime(int n) {
    if (n == 2) return true;
    if (n <= 1 || n % 2 == 0) return false;
    int last = sqrt(n) + 1;
    for (int i = 3; i <= last; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int findNextPrime(int n) {
    for (int i = n; i < INT_MAX; ++i) {
        if (isPrime(i)) return i;
    }
    return -1;
}
array<int, 100000> vec;

int main() {
    ios::sync_with_stdio(false);
    int MSize, N, M;
    cin >> MSize >> N >> M;
    MSize = findNextPrime(MSize);
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        int static_posi = tmp % MSize;
        int posi = static_posi;
        int ratio = 1;
        bool success = false;
        for (int j = 0; j < MSize + 1; ++j) {
            if (vec[posi] == 0) {
                vec[posi] = tmp;
                success = true;
                break;
            }
            else {
                posi = (static_posi + ratio * ratio) % MSize;
            }
            ratio++;
        }
        if (!success) cout << tmp << " cannot be inserted." << endl;
    }
    int sum = 0;
    for (int i = 0; i < M; ++i) {
        int tmp;
        cin >> tmp;
        int static_posit = tmp % MSize;
        int posi = static_posit;
        int ratio = 1;
        bool success = false;
        for (int j = 0; j < MSize + 1; ++j) {
            if (vec[posi] == tmp || vec[posi] == 0) {
                success = true;
                sum += j + 1;
                break;
            }
            else {
                posi = (static_posit + ratio * ratio) % MSize;
            }
            ratio++;
        }
        if (!success) sum += MSize + 1;
    }
    char buf[100];
    sprintf(buf, "%.1f\n", sum * 1.0 / M + 0.001);
    cout << buf;
    return 0;
}
