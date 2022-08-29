#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct Student {
    string name;
    int G = -1;
    int Gmid = -1;
    int Gfinal = -1;
    int Gprogramming = -1;
    bool operator<(const Student& other) const {
        if (G > other.G) return true;
        else if (G == other.G) return name < other.name;
        return false;
    }

};

int main() {
    int P, M, N;
    vector<Student> students;
    map<string, int> MAP;
    cin >> P >> M >> N;
    decltype(students.end()) it;
    for (int i = 0; i < P; ++i) {
        string name;
        cin >> name;
        if (MAP.find(name) == MAP.end()) {
            Student tmp;
            tmp.name = name;
            cin >> tmp.Gprogramming;
            students.push_back(tmp);
            MAP[name] = students.size() - 1;
        }
        else {
            cin >> students[MAP[name]].Gprogramming;
        }
    }
    for (int i = 0; i < M; ++i) {
        string name;
        cin >> name;
        if (MAP.find(name) == MAP.end()) {
            Student tmp;
            tmp.name = name;
            cin >> tmp.Gmid;
            students.push_back(tmp);
            MAP[name] = students.size() - 1;
        }
        else {
            cin >> students[MAP[name]].Gmid;
        }
    }
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        if (MAP.find(name) == MAP.end()) {
            Student tmp;
            tmp.name = name;
            cin >> tmp.Gfinal;
            students.push_back(tmp);
            MAP[name] = students.size() - 1;
        }
        else {
            cin >> students[MAP[name]].Gfinal;
            int mid = students[MAP[name]].Gmid;
            int final = students[MAP[name]].Gfinal;
            int& g = students[MAP[name]].G;
            if (mid > final) {
                g = round(mid * .4 + final * .6);
            }
            else {
                g = final;
            }
        }
    }
    sort(students.begin(), students.end());
    for (auto& s: students) {
        if (s.Gprogramming >= 200 && s.G >= 60 && s.G <= 100) {
            cout << s.name << " " << s.Gprogramming << " " << s.Gmid << " " << s.Gfinal << " " << s.G << '\n';
        }
    }
    return 0;
}
