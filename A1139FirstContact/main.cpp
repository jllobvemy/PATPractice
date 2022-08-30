#include <bits/stdc++.h>
// Not ac.
using namespace std;
constexpr int MAXLEN = 301;
enum class Gender {
    Male, Female, Unknown
};
struct Person {
    Gender g = Gender::Unknown;
    int index = -1;
};
map<int, int> name2index;
map<int, int> index2name;
int CURT = 0;
int GetIndex(int name) {
    if (name2index.find(name) == name2index.end()) {
        name2index[name] = CURT;
        index2name[CURT] = name;
        CURT++;
        return CURT - 1;
    }
    else return name2index[name];
}
int GetName(int id) {
    return index2name[id];
}
int M, N;
vector<Person> Adj[MAXLEN];
array<Person, MAXLEN> persons;
array<bool, MAXLEN> visited;
int Start, End;
vector<int> tmpans;
vector<vector<int>> ans;

void DFS(int n, int depth) {
    if (depth > 3)
        return;
    for (auto& i: Adj[n]) {
        if (!visited[i.index]) {
            if (depth == 0) {
                if (persons[Start].g != persons[i.index].g) continue;
            }
            if (depth == 1) {
                if (persons[End].g != persons[i.index].g) continue;
            }
            if (depth == 2 && i.index == End) {
                ans.push_back(tmpans);
                break;
            }
            visited[i.index] = true;
            tmpans.push_back(i.index);
            DFS(i.index, depth + 1);
            tmpans.pop_back();
            visited[i.index] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> M >> N;
    for (int i = 0; i < N; ++i) {
        string sa, sb;
        cin >> sa >> sb;
        int a = stoi(sa), b = stoi(sb);
        Person tmpa, tmpb;
        tmpa.index = GetIndex(abs(a));
        tmpa.g = sa[0] != '-'? Gender::Male: Gender::Female;
        tmpb.index = GetIndex(abs(b));
        tmpb.g = sb[0] != '-'? Gender::Male: Gender::Female;
        a = GetIndex(abs(a)); b = GetIndex(abs(b));
        persons[a] = tmpa;
        persons[b] = tmpb;
        Adj[a].push_back(tmpb);
        Adj[b].push_back(tmpa);
    }
    int K;
    cin >> K;
    char buf[100];
    for (int i = 0; i < K; ++i) {
        cin >> Start >> End;
        ans.clear();
        Start = GetIndex(abs(Start));
        End = GetIndex(abs(End));
        visited[Start] = true;
        DFS(Start, 0);
        visited[Start] = false;
        cout << ans.size() << endl;
        sort(ans.begin(), ans.end(), [](auto& e1, auto& e2) {
            if (GetName(e1[0]) < GetName(e2[0])) return true;
            else if (GetName(e1[0]) == GetName(e2[0])) return GetName(e1[1]) < GetName(e2[1]);
            return false;
        });
        for (auto& e: ans) {
            sprintf(buf, "%04d %04d\n", GetName(e[0]), GetName(e[1]));
            cout << buf;
        }
    }
    return 0;
}
