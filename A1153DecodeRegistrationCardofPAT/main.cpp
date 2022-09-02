#include <bits/stdc++.h>
// Accepted!
using namespace std;
#define endl '\n'

char GetLevel(string& s) {
    return s[0];
}

int GetSite(string& s) {
    return stoi(s.substr(1, 3));
}

int GetDate(string& s) {
    return stoi(s.substr(4, 6));
}

int GetId(string& s) {
    return stoi(s.substr(10, 3));
}
unordered_map<char, vector<int>> Level2User;
unordered_map<int, vector<int>> Site2User;
unordered_map<int, set<int>> Date2Site;
unordered_map<int, vector<int>> Date2SiteV;
unordered_map<int, int> User2Score;
unordered_map<int, int> DateSite2Num;
vector<string> vs;
bool cmpScore(int a, int b) {
    if (User2Score[a] > User2Score[b]) return true;
    if (User2Score[a] == User2Score[b]) {
        return vs[a] < vs[b];
    }
    return false;
}
int CurtDate;
bool cmpDate(int a, int b) {
    int dateSitea = CurtDate * 1000 + a;
    int dateSiteb = CurtDate * 1000 + b;
    if (DateSite2Num[dateSitea] > DateSite2Num[dateSiteb]) return true;
    if (DateSite2Num[dateSitea] == DateSite2Num[dateSiteb]) {
        return a < b;
    }
    return false;
}

int GetScoreSum(vector<int>& vec) {
    int sum = 0;
    for (auto e: vec) {
        sum += User2Score[e];
    }
    return sum;
}



int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vs.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> vs[i];
        int score;
        cin >> score;
        User2Score[i] = score;
        string& s = vs[i];
        Level2User[GetLevel(s)].push_back(i);
        int date = GetDate(s);
        int site = GetSite(s);
        Site2User[site].push_back(i);
        DateSite2Num[date * 1000 + site]++;
        if (Date2Site[date].find(site) == Date2Site[date].end()) {
            Date2Site[GetDate(s)].insert(GetSite(s));
            Date2SiteV[GetDate(s)].push_back(GetSite(s));
        }
    }
    char buf[100];
    for (int i = 0; i < M; ++i) {
        int t;
        cin >> t;
        bool printed = false;
        switch (t) {
            case 1:
                char l;
                cin >> l;
                sprintf(buf, "Case %d: %d %c\n", i + 1, 1, l);
                cout << buf;
                sort(Level2User[l].begin(), Level2User[l].end(), cmpScore);
                for (auto e: Level2User[l]) {
                    printed = true;
                    cout << vs[e] << " " << User2Score[e] << endl;
                }
                break;
            case 2:
                int q;
                cin >> q;
                sprintf(buf, "Case %d: %d %d\n", i + 1, 2, q);
                cout << buf;
                if (!Site2User[q].empty()) {
                    cout << Site2User[q].size() << " " << GetScoreSum(Site2User[q]) << endl;
                    printed = true;
                }
                break;
            case 3:
                int date;
                cin >> date;
                CurtDate = date;
                sprintf(buf, "Case %d: %d %06d\n", i + 1, 3, date);
                cout << buf;
                sort(Date2SiteV[date].begin(), Date2SiteV[date].end(), cmpDate);
                for (auto e: Date2SiteV[date]) {
                    printed = true;
                    int datesite = date * 1000 + e;
                    cout << e << " " << DateSite2Num[datesite] << endl;
                }
                break;
            default:
                return 1;
        }
        if (!printed) cout << "NA" << endl;

    }

    return 0;
}
