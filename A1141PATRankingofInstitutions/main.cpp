#include <bits/stdc++.h>
using namespace std;
struct School {
    string Name;
    int TWS = 0;
    int T = 0, A = 0, B = 0;
    int Ns = 0;
    bool operator<(const School& other) const {
        if (TWS > other.TWS) return true;
        else if (TWS == other.TWS) {
            if (Ns < other.Ns) return true;
            else if (Ns == other.Ns) {
                return Name < other.Name;
            }
        }
        return false;
    }
};
void GetScore(School& s, int score, char level) {
    switch (level) {
        case 'A':
            s.A += score;
            break;
        case 'B':
            s.B += score;
            break;
        case 'T':
            s.T += score;
            break;
    }
}
map<string, int> SchoolMap;
vector<School> schools;


int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string school, id;
        int score;
        cin >> id >> score >> school;
        for (auto& e: school) {
            e = tolower(e);
        }
        if (SchoolMap.find(school) == SchoolMap.end()) {
            School tmp;
            tmp.Name = school;
            tmp.Ns++;
            GetScore(tmp, score, id[0]);
            schools.push_back(tmp);
            SchoolMap[school] = schools.size() - 1;
        }
        else {
            auto& s = schools[SchoolMap[school]];
            GetScore(s, score, id[0]);
            s.Ns++;
        }
    }
    for (auto& s: schools) {
        s.TWS = s.B / 1.5 + s.A + s.T * 1.5;
    }
    sort(schools.begin(), schools.end());
    cout << schools.size() << endl;
    if (schools.empty()) return 0;
    char buf[100];
    int rank = 1;
    int offset = 1;
    sprintf(buf, "%d %s %d %d\n", rank, schools[0].Name.c_str(),schools[0].TWS, schools[0].Ns);
    cout << buf;
    for (int i = 1; i < schools.size(); ++i) {
        int last = schools[i - 1].TWS;
        int curt = schools[i].TWS;
        if (last == curt) {
            offset++;
        }
        else {
            rank += offset;
            offset = 1;
        }
        sprintf(buf, "%d %s %d %d\n", rank, schools[i].Name.c_str(), schools[i].TWS, schools[i].Ns);
        cout << buf;
    }

    return 0;
}
