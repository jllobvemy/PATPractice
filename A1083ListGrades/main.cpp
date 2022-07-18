#include <bits/stdc++.h>
using namespace std;
struct Student {
    char name[15];
    char ID[15];
    int grade;
    bool operator<(const Student& a) const {
        return grade > a.grade;
    }
};
int N;

int main() {
    int grade1, grade2;
    multiset<Student> students;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        Student s;
        cin >> s.name >> s.ID >> s.grade;
        students.insert(s);
    }
    cin >> grade1 >> grade2;
    auto lower = std::find_if(students.begin(), students.end(), [grade2](auto x) {
        return x.grade <= grade2;
    });
    auto upper = std::find_if(students.rbegin(), students.rend(), [grade1](auto x){
        return x.grade >= grade1;
    }).base();
    int cnt = 0;
    bool first = true;
    auto i = lower;
    do {
        if (i == upper) break;
        if (!first) cout << endl;
        else first = false;
        cout << i->name << " " << i->ID;
        i++;
        cnt++;
    } while (true);
    if (cnt == 0) cout << "NONE" << endl;

    return 0;
}
