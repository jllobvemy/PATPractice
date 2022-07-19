#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr double epsilon = 0.0001;
int N, M, K; // N 40000; M 100; K 5;
int quotas[110];
struct Student {
    int GE, GI;
    int schools[5];
    int rank;
    bool registered = false;
    int num;
};
bool cmp(const Student& a, const Student& b) {
    double m1 = (a.GE + a.GI) / 2.0;
    double m2 = (b.GE + b.GI) / 2.0;
    double diff = m1 - m2;
    if (diff > epsilon) return true;
    else if (abs(diff) < epsilon) return a.GE > b.GE;
    return false;
}
bool sameGrade(const Student& a, const Student& b) {
    double m1 = (a.GE + a.GI) / 2.0;
    double m2 = (b.GE + b.GI) / 2.0;
    double diff = m1 - m2;
    if (abs(diff) < epsilon)
        return a.GE == b.GE;
    return false;
}

array<Student, 40000> students;
array<vector<int>, 100> schoolQuota;

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        cin >> quotas[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> students[i].GE >> students[i].GI;
        for (int j = 0; j < K; ++j) {
            cin >> students[i].schools[j];
            students[i].num = i;
        }
    }
    sort(students.begin(), students.begin() + N, cmp);
    students[0].rank = 1;
    int offset = 1;
    for (int i = 1; i < N; ++i) {
        if (sameGrade(students[i], students[i-1])) {
            students[i].rank = students[i - 1].rank;
            offset++;
        }
        else {
            students[i].rank = students[i - 1].rank + offset;
            offset = 1;
        }
    }
    for (int i = 0; i < N; ++i) { // student's num
        for (int j = 0; j < K; ++j) {
            int selectedSchool = students[i].schools[j];
            if (schoolQuota[selectedSchool].size() < quotas[selectedSchool]) {
                schoolQuota[selectedSchool].push_back(i);
                goto end;
            }
            else if (students[schoolQuota[selectedSchool].back()].rank == students[i].rank) {
                schoolQuota[selectedSchool].push_back(i);
                goto end;
            }
        }
        end:;
    }
    for (int i = 0; i < M; ++i) {
        bool firstNum = true;
        sort(schoolQuota[i].begin(), schoolQuota[i].end(), [](int a, int b){
            return students[a].num < students[b].num;
        });
        for (int j : schoolQuota[i]) {
            if (firstNum) firstNum = false;
            else cout << " ";
            cout << students[j].num;
        }
        cout << endl;
    }
    return 0;
}
