#include <bits/stdc++.h>
// ACCEPTED!!
// 注意不大于、大于等等问题
using namespace std;
struct Student;
int Judge(const Student& s);
int N, L, H;

struct Student {
    ulong number;
    short de, cai;
    Student(ulong n, short de, short cai): number(n), de(de), cai(cai) {}
    bool operator<(const Student& right) const {
        int JL = Judge(*this);
        int JR = Judge(right);
        if (JL != JR) return JL > JR;
        int sumL = de + cai, sumR = right.de + right.cai;
        if (sumL != sumR) return sumL > sumR;
        if (de != right.de) return de > right.de;
        return number < right.number;
    }
};
int Judge(const Student& s) {
    if (s.de >= H && s.cai >= H) return 4;
    if (s.de >= H && s.cai < H) return 3;
    if (s.cai <= s.de) return 2;
    return 1;
}
vector<Student> students;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> L >> H;
    for (int i = 0; i < N; ++i) {
        ulong num;
        short de, cai;
        cin >> num >> de >> cai;
        if (de >= L && cai >= L)
            students.emplace_back(num, de, cai);
    }
    sort(students.begin(), students.end());
    cout << students.size() << endl;
    for (auto i = students.begin(); i < students.end(); ++i) {
        cout << i->number << " " << i->de << " " << i->cai;
        if (i + 1 != students.end()) cout << endl;
    }
    return 0;
}
