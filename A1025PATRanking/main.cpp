#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct Student {
    string name;
    int final_rank;
    int local_number;
    int local_rank;
    int score;
    Student(string n, int f, int ln, int lr): name(std::move(n)), final_rank(f), local_number(ln), local_rank(lr) {}
    Student(string n, int score, int ln): score(score), name(std::move(n)), local_number(ln) {}
};

bool cmp_score(const Student& s1, const Student& s2) {
    if (s1.score > s2.score) {
        return true;
    }
    else if (s1.score == s2.score) {
        return s1.name < s2.name;
    }
    return false;
}
int main() {
    int K, N;
    cin >> K;
    vector<Student> studentstmp;
    vector<Student> studentsAll;
    for (int i = 0; i < K; ++i) {
        cin >> N;
        for (int j = 0; j < N; ++j) {
            string name;
            int score;
            cin >> name >> score;
            studentstmp.emplace_back(name, score, i + 1);
        }
        sort(studentstmp.begin(), studentstmp.end(), cmp_score);
        int rank = 1;
        int offset = 1;
        studentstmp.begin()->local_rank = 1;
        for (auto it = studentstmp.begin() + 1; it != studentstmp.end(); it++) {
            if (it->score == (it - 1)->score) {
                it->local_rank = (it - 1)->local_rank;
                offset++;
            }
            else {
                it->local_rank = rank += offset;
                offset = 1;
            }
        }
        studentsAll.insert(studentsAll.end(), studentstmp.begin(), studentstmp.end());
        studentstmp.clear();
    }
    sort(studentsAll.begin(), studentsAll.end(), cmp_score);
    int rank = 1;
    int offset = 1;
    studentsAll.begin()->final_rank = 1;
    for (auto it = studentsAll.begin() + 1; it != studentsAll.end(); it++) {
        if (it->score == (it - 1)->score) {
            it->final_rank = (it - 1)->final_rank;
            offset++;
        }
        else {
            it->final_rank = rank += offset;
            offset = 1;
        }
    }
    cout << studentsAll.size() << endl;
    for (auto& s: studentsAll) {
        cout << s.name << " " << s.final_rank << " " << s.local_number << " " << s.local_rank << endl;
    }


}