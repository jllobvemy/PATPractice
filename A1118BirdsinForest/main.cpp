#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 10010;
array<int, MAXLEN> birds;
int FindFather(int n) {
    if (n == birds[n]) return n;
    birds[n] = FindFather(birds[n]);
    return birds[n];
}

void Union(int a, int b) {
    int fa = FindFather(a);
    int fb = FindFather(b);
    if (fa != fb) {
        birds[fb] = fa;
    }
}


int main() {
    for (int i = 0; i < MAXLEN; ++i) {
        birds[i] = i;
    }
    int N;
    cin >> N;
    vector<int> allbirds;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        int father;
        for (int j = 0; j < num; ++j) {
            int b;
            cin >> b;
            allbirds.push_back(b);
            if (j == 0) {
//                if (birds[j] == -1) birds[b] = b;
                father = FindFather(b);
            }
            else {
                Union(father, b);
            }
        }
    }
    sort(allbirds.begin(), allbirds.end());
    auto it = unique(allbirds.begin(), allbirds.end());
    int notGroupCount = 0;
    for (int i = 0; i < MAXLEN; ++i) {
        if (birds[i] != i) notGroupCount++;
    }
    int groupCount = it - allbirds.begin() - notGroupCount;
    cout << groupCount << " " << it - allbirds.begin() << endl;
    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        if (FindFather(a) == FindFather(b)) {
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
    }
    return 0;
}
