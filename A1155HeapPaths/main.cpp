#include <bits/stdc++.h>
// Accepted!
using namespace std;
vector<vector<int>> Paths;
vector<int> Heap;
int N;
vector<int> tmp;
void DFS(int i) {
    tmp.push_back(Heap[i]);
    bool flag = false;
    if (2 * i + 1 <= N) {
        DFS(2 * i + 1);
        flag = true;
    }
    if (2 * i <= N) {
        DFS(2 * i);
        flag = true;
    }
    if (!flag) {
        Paths.push_back(tmp);
    }
    tmp.pop_back();
}


int main() {
    cin >> N;
    Heap.resize(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> Heap[i];
    }
    DFS(1);
    bool isMax = true, isMin = true;
    for (int i = 2; i <= N; ++i) {
        if (Heap[i / 2] > Heap[i]) isMin = false;
        if (Heap[i / 2] < Heap[i]) isMax = false;
    }
    for (auto& p: Paths) {
        bool first = true;
        for (auto& e: p) {
            if (first) first = false;
            else cout << " ";
            cout << e;
        }
        cout << endl;
    }
    if (isMin) cout << "Min Heap" << endl;
    else if (isMax) cout << "Max Heap" << endl;
    else cout << "Not Heap" << endl;
    return 0;
}
