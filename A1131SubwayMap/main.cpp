#include <bits/stdc++.h>
// Not complete.
constexpr int MAXLEN = 1200;
constexpr int INF = INT_MAX / 2 - 1;
using namespace std;
vector<int> Adj[MAXLEN];
int CurtIndex = 0;
map<string, int> Name2Index;
map<int, string> Index2Name;
map<int, set<int>> Index2Line;
int GetIndex(const string& s) {
    if (Name2Index.find(s) == Name2Index.end()) {
        Name2Index[s] = CurtIndex;
        Index2Name[CurtIndex] = s;
        CurtIndex++;
    }
    return Name2Index[s];
}
int GetNum() {
    return Name2Index.size();
}
const string& GetName(int i) {
    return Index2Name[i];
}
bool isSameLine(int s1, int s2, int s3) {
    set<int> tmp;
    set_intersection(Index2Line[s1].begin(), Index2Line[s1].end(), Index2Line[s2].begin(), Index2Line[s2].end(),
                     inserter(tmp, tmp.begin()));
    if (tmp.size() > 1) exit(2);
    if (Index2Line[s3].find(*tmp.begin()) != Index2Line[s3].end()) return true;
    return false;
}

int SameLine(int s1, int s2) {
    set<int> tmp;
    set_intersection(Index2Line[s1].begin(), Index2Line[s1].end(), Index2Line[s2].begin(), Index2Line[s2].end(),
                     inserter(tmp, tmp.begin()));
    if (tmp.empty()) exit(4);
    return *tmp.begin();
}

array<bool, MAXLEN> visited;
vector<int> pre[MAXLEN];
array<int, MAXLEN> d;
void Init() {
    for (int i = 0; i < MAXLEN; ++i) {
        d[i] = INF;
    }
}

void Dijkstra(int node) {
    fill(visited.begin(), visited.end(), false);
    fill(pre, pre + MAXLEN, vector<int>());
    d[node] = 0;
    for (int i = 0; i < GetNum(); ++i) {
        int u = -1, minLen = INF;
        for (int j = 0; j < GetNum(); ++j) {
            if (!visited[j] && d[j] < minLen) {
                u = j;
                minLen = d[j];
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for (auto v: Adj[u]) {
            if (!visited[v]) {
                if (d[u] + 1 < d[v]) {
                    d[v] = d[u] + 1;
                    pre[v].clear();
                    pre[v].push_back(u);
                }
                else if (d[u] + 1 == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
vector<int> PathTmp;
vector<vector<int>> Paths;

void DFS(int end) {
    if (pre[end].empty())  {
        PathTmp.push_back(end);
        Paths.push_back(PathTmp);
        PathTmp.pop_back();
        return;
    }
    PathTmp.push_back(end);
    for (auto i: pre[end]) {
        DFS(i);
    }
    PathTmp.pop_back();
}
vector<vector<int>>& GetPath(int end) {
    Paths.clear();
    DFS(end);
    for (auto& p: Paths) {
        std::reverse(p.begin(), p.end());
    }
    return Paths;
}
void PrintLine(const vector<int>& line) {
    char buf[50];
    if (line.size() < 2) return;
    cout << line.size() - 1 << endl;
    if (line.size() <= 2) {
        auto s1 = GetName(line[0]);
        auto s2 = GetName(line[1]);
        sprintf(buf, "Take Line#%d from %s to %s.", SameLine(line[0], line[1]), s1.c_str(), s2.c_str());
        cout << buf << endl;
        return ;
    }
    int begin = line.front();
    int end = line.back();
    for (int i = 0; i < line.size() - 2; ++i) {
        int left = line[i];
        int mid = line[i + 1];
        int right = line[i + 2];
        if (isSameLine(left, mid, right)) {
//            end = right;
        }
        else {
            auto s1 = GetName(begin);
            auto s2 = GetName(mid);
            sprintf(buf, "Take Line#%d from %s to %s.", SameLine(begin, mid), s1.c_str(), s2.c_str());
            cout << buf << endl;
            begin = mid;
        }
    }
    auto s1 = GetName(begin);
    auto s2 = GetName(end);
    sprintf(buf, "Take Line#%d from %s to %s.", SameLine(begin, end), s1.c_str(), s2.c_str());
    cout << buf << endl;
}
int main() {
    Init();
    int LineNum;
    cin >> LineNum;
    for (int i = 0; i < LineNum; ++i) {
        int num;
        cin >> num;
        string s1;
        cin >> s1;
        for (int j = 0; j < num - 1; ++j) {
            Index2Line[GetIndex(s1)].insert(i + 1);
            string s2;
            cin >> s2;
            int i1 = GetIndex(s1), i2 = GetIndex(s2);
            Adj[i1].push_back(i2);
            Adj[i2].push_back(i1);
            s1 = s2;
        }
    }
    int qnum;
    cin >> qnum;
    for (int i = 0; i < qnum; ++i) {
        string start, end;
        cin >> start >> end;
        int i1 = GetIndex(start), i2 = GetIndex(end);
        Dijkstra(i1);
        const auto& paths = GetPath(i2);
        PrintLine(paths[0]);
    }
    return 0;
}
