#include <bits/stdc++.h>
// Accepted!
using namespace std;
array<int, 550> father;

int findFather(int a) {
    if (father[a] == a) return a;
    father[a] = findFather(father[a]);
    return father[a];
}
void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa != fb) {
        father[fb] = fa;
    }
}

int main() {
    for (int i = 0; i < father.size(); ++i) {
        father[i] = i;
    }
    int N, M;
    cin >> N >> M;
    bool first = true;
    if (N == 0) return 1;
    if (M == 0) {
        for (int i = 0; i < N; ++i) {
            if (first) first = false;
            else cout << " ";
            cout << 0;
        }
        cout << "\nEulerian";
        return 0;
    }
    map<int, int> G;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a]++;
        G[b]++;
        Union(a, b);
    }
    int oddnum = 0;
    int evennum = 0;
    int cnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (father[i] == i) cnt++;
    }
    first = true;
    for (auto [a, cnt]: G) {
        if (cnt % 2) oddnum++;
        else evennum++;
        if (first) first = false;
        else cout << " ";
        cout << cnt;
    }
    cout << endl;
    if (evennum == N && cnt == 1) {
        cout << "Eulerian" << endl;
    }
    else if (oddnum == 2 && cnt == 1) {
        cout << "Semi-Eulerian" << endl;
    }
    else {
        cout << "Non-Eulerian" << endl;
    }
    return 0;
}
