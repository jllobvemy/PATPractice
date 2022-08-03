#include <bits/stdc++.h>
// Accepted!
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    map<string, vector<short>> stu2course;
    int N; // number of students who look for their course lists
    int K; // total number of courses
    cin >> N >> K;
    auto stringhash = hash<string>();
    for (int i = 0; i < K; ++i) {
        int index, num;
        cin >> index >> num;
        for (int j = 0; j < num; ++j) {
            string name;
            cin >> name;
            stu2course[move(name)].push_back(index);
        }
    }
    bool firstline = true;
    for (int i = 0; i < N; ++i) {
        string name;
        cin >> name;
        if (firstline) {
            firstline = false;
        }
        else {
            cout << endl;
        }
        cout << name << " ";
        auto found = stu2course.find(name);
        if (found != stu2course.end()) {
            cout << found->second.size();
            if (!found->second.empty()) {
                sort(found->second.begin(), found->second.end());
                for (auto e: found->second) {
                    cout << " " << e;
                }
            }
        }
        else {
            cout << 0;
        }
    }
    return 0;
}
