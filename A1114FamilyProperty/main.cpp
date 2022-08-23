#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 10010;
struct Node {
    int estateNum = 0;
    double estateArea = 0;
    int ID = INT_MAX;
};
array<Node, MAXLEN> Persons;
vector<int> Adj[MAXLEN];
array<bool, MAXLEN> visited;
struct Family{
    int sId = INT_MAX;
    int member = 0;
    double AvgSet = 0;
    double AveArea = 0;
    int Num = 0;
    double Area = 0;
    bool operator<(const Family& other) const {
        if (AveArea > other.AveArea) return true;
        else if (AveArea == other.AveArea) return sId < other.sId;
        return false;
    }
};
Family tmpFamily;

void DFS(int n) {
    visited[n] = true;
    if (tmpFamily.sId > n) {
        tmpFamily.sId = n;
    }
    tmpFamily.member++;
    tmpFamily.Num += Persons[n].estateNum;
    tmpFamily.Area += Persons[n].estateArea;
    for (auto e: Adj[n]) {
        if (!visited[e])
            DFS(e);
    }
}
vector<Family> ans;

void DFSTraverse() {
    for (int i = 0; i < MAXLEN; ++i) {
        if (!visited[i] && Persons[i].ID != INT_MAX) {
            DFS(i);
            Family tmp;
            tmpFamily.AveArea = tmpFamily.Area / tmpFamily.member;
            tmpFamily.AvgSet = tmpFamily.Num * 1.0 / tmpFamily.member;
            ans.push_back(tmpFamily);
            tmpFamily = tmp;
        }
    }
}

int main() {
    int N;
    char buf[100];
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int ID, Father, Mother, ChildrenNum, Set;
        double  Area;
        cin >> ID >> Father >> Mother >> ChildrenNum;
        if (Father != -1) {
            Adj[ID].push_back(Father);
            Adj[Father].push_back(ID);
        }
        if (Mother != -1) {
            Adj[ID].push_back(Mother);
            Adj[Mother].push_back(ID);
        }
        vector<int> tmpChildren;
        for (int j = 0; j < ChildrenNum; ++j) {
            int tmp;
            cin >> tmp;
            Adj[ID].push_back(tmp);
            Adj[tmp].push_back(ID);
            tmpChildren.push_back(tmp);
        }
        cin >> Set >> Area;
        Persons[ID].ID = ID;
        Persons[ID].estateArea = Area;
        Persons[ID].estateNum = Set;
    }
    DFSTraverse();
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto& e: ans) {
        sprintf(buf, "%04d %d %.3f %.3f\n", e.sId, e.member, e.AvgSet, e.AveArea);
        cout << buf;
    }


    return 0;
}
