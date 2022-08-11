#include <bits/stdc++.h>
// Accepted! 邻接矩阵 + DFS
using namespace std;
constexpr int MAXLEN = 2050;
map<int, string> id2name;
map<string, int> name2id;
int curID = 0;
int N, T;
array<int, MAXLEN> personTime;
array<bool, MAXLEN> visited;
array<array<int, MAXLEN>, MAXLEN> G;

int getId(const string& n) {
    if (name2id.find(n) == name2id.end()) {
        name2id[n] = curID;
        id2name[curID] = n;
        return curID++;
    }
    else {
        return name2id[n];
    }
}
const string& getName(int i) {
    if (id2name.find(i) == id2name.end()) {
        exit(3);
    }
    else {
        return id2name[i];
    }
}
int getPersonNum() {
    return name2id.size();
}
int curtPersonNum = 0;
int curtGangTime = 0;
int curtHead = -1;

void DFS(int v) {
    if (!visited[v]) curtPersonNum++;
    if (personTime[v] > personTime[curtHead]) curtHead = v;
    visited[v] = true;
    for (int i = 0; i < getPersonNum(); i++) {
        if (G[v][i] > 0) {
            curtGangTime += G[v][i];
            G[i][v] = 0;
            G[v][i] = 0;
            if (!visited[i]) {
                DFS(i);
            }
        }
    }
}

map<string, int> ans;
void DFSTraverse() {
    int num = getPersonNum();
    for (int i = 0; i < num; ++i) {
        if (!visited[i]) {
            curtHead = i;
            curtPersonNum = 0;
            curtGangTime = 0;
            DFS(i);
            if (curtPersonNum > 2 && curtGangTime > T) {
                ans[getName(curtHead)] = curtPersonNum;
            }
        }
    }
}
int main() {
    cin >> N >> T;
    for (int i = 0; i < N; ++i) {
        string name1, name2;
        int t;
        cin >> name1 >> name2 >> t;
        int id1 = getId(name1), id2 = getId(name2);
        personTime[id1] += t;
        personTime[id2] += t;
        G[id1][id2] += t;
        G[id2][id1] += t;
    }
    DFSTraverse();
    cout << ans.size() << endl;
    for (const auto& i: ans) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}



