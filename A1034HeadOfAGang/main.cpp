#include <bits/stdc++.h>
// Accepted! 并查集解法
constexpr int MAXLEN = 3000;
using namespace std;
map<int, string> id2name;
map<string, int> name2id;
int curID = 0;
int N, T;
array<int, MAXLEN> father;
array<int, MAXLEN> personTime;
array<int, MAXLEN> gangTime;
array<int, MAXLEN> gangPerson;

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

int findFather(int a) {
    if (a == father[a]) return a;
    return findFather(father[a]);
}

void Union(int a, int b) {
    int fa = findFather(a);
    int fb = findFather(b);
    if (fa != fb) {
        if (personTime[fa] > personTime[fb]) {
            father[fb] = fa;
            gangTime[fa] += gangTime[fb];
            gangPerson[fa] += gangPerson[fb];
            gangTime[fb] = 0;
            gangPerson[fb] = 0;
        }
        else {
            father[fa] = fb;
            gangTime[fb] += gangTime[fa];
            gangPerson[fb] += gangPerson[fa];
            gangTime[fa] = 0;
            gangPerson[fa] = 0;
        }
    }
}


int main() {
    for (int i = 0; i < MAXLEN; ++i) {
        father[i] = i;
        personTime[i] = 0;
        gangTime[i] = 0;
        gangPerson[i] = 0;
    }
    cin >> N >> T;
    vector<pair<int, int>> tmp;
    for (int i = 0; i < N; ++i) {
        string name1, name2;
        int t;
        cin >> name1 >> name2 >> t;
        personTime[getId(name1)] += t;
        personTime[getId(name2)] += t;
        tmp.emplace_back(getId(name1), getId(name2));
        gangTime[findFather(getId(name1))] += t;
        gangPerson[findFather(getId(name1))] += 1;
    }
    for (const auto& i: tmp) {
        Union(i.first, i.second);
    }
    map<string, int> ans;
    for (int i = 0; i < name2id.size(); ++i) {
        int cfather = findFather(i);
        if (gangPerson[cfather] > 2 && gangTime[cfather] > T) {
            ans[getName(cfather)]++;
        }
    }
    cout << ans.size() << endl;
    for (const auto& i: ans) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
