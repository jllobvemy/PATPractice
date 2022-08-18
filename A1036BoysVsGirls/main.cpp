#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct Student {
    string name;
    string ID;
    int score;
};

bool cmpMale(Student& a, Student& b) {
    return a.score < b.score;
}
bool cmpFemale(Student& a, Student& b) {
    return a.score > b.score;
}

int main() {
    vector<Student> male;
    vector<Student> female;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        Student tmp;
        string gender;
        cin >> tmp.name >> gender >> tmp.ID >> tmp.score;
        if (gender == "M") {
            male.push_back(tmp);
        }
        else {
            female.push_back(tmp);
        }
    }
    sort(male.begin(), male.end(), cmpMale);
    sort(female.begin(), female.end(), cmpFemale);
    if (male.empty()) {
        cout << female.front().name << " " << female.front().ID << endl;
        cout << "Absent" << endl;
        cout << "NA" << endl;
        return 0;
    }
    if (female.empty()) {
        cout << "Absent" << endl;
        cout << male.front().name << " " << male.front().ID << endl;
        cout << "NA" << endl;
        return 0;

    }
    int dif = female.front().score - male.front().score;
    cout << female.front().name << " " << female.front().ID << endl;
    cout << male.front().name << " " << male.front().ID << endl;
    cout << dif << endl;
    return 0;
}
