#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 1010;
int M, N;
array<int, MAXLEN> Heap;
bool first = true;
void PostOrder(int n) {
    if (n > N) return;
    PostOrder(n * 2);
    PostOrder(n * 2 + 1);
    if (first) first = false;
    else cout << " ";
    cout << Heap[n];
}


int main() {
    cin >> M >> N;
    for (int i = 0; i < M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> Heap[j];
        }
        bool isMin = true, isMax = true;
        for (int j = 2; j <= N; ++j) {
            if (Heap[j] > Heap[j / 2]) isMax = false;
            if (Heap[j] < Heap[j / 2]) isMin = false;
        }
        if (isMax) {
            cout << "Max Heap" << endl;
        }
        else if (isMin) {
            cout << "Min Heap" << endl;
        }
        else {
            cout << "Not Heap" << endl;
        }
        first = true;
        PostOrder(1);
        cout << endl;
    }
    return 0;
}
