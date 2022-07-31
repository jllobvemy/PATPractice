#include <bits/stdc++.h>
// Accepted!
using namespace std;
array<int, 150> floors;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> floors[i];
    }
    int currentFloor = 0;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int delta = floors[i] - currentFloor;
        currentFloor = floors[i];
        sum += delta > 0? delta * 6 : -delta * 4;
        sum += 5;
    }
    cout << sum;
    return 0;
}
