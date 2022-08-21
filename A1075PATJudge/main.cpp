#include <bits/stdc++.h>
// Accepted!
using namespace std;
constexpr int MAXLEN = 100050;

struct Student {
    array<optional<int>, 6> scores;
    int sum;
    int perfectNum = 0;
    int id;
    bool pass = false;
    bool operator<(const Student& other) const {
        if (!pass) return false;
        if (!other.pass) return true;
        if (sum > other.sum) return true;
        else if (sum == other.sum) {
            if (perfectNum > other.perfectNum) return true;
            else if (perfectNum == other.perfectNum) return id < other.id;
        }
        return false;
    }
};
array<Student, MAXLEN> students;
void PrintScores(array<optional<int>, 6>& scores, int num) {
    bool first = true;
    for (int i = 1; i <= num; ++i) {
        if (!first) cout << " ";
        else first = false;
        if (scores[i].has_value()) cout << scores[i].value();
        else cout << '-';
    }
}

int main() {
    int N, K, M;
    cin >> N >> K >> M;
    array<int, 6> maxScores {};
    for (int i = 1; i <= K; ++i) {
        cin >> maxScores[i];
    }
    for (int i = 0; i < M; ++i) {
        int id, pid, score;
        cin >> id >> pid >> score;
        if (score == -1) score = 0;
        else students[id].pass = true;
        students[id].id = id;
        auto &curtScore = students[id].scores[pid];
        if (curtScore.has_value()) {
            if (score > curtScore.value()) curtScore.value() = score;
        }
        else curtScore = score;
    }
    int num = 0;
    for (int i = 0; i < MAXLEN; ++i) {
        int cnt = 0;
        if (!students[i].pass) continue;
        for (int j = 1; j <= K; ++j) {
            if (students[i].scores[j].has_value()) {
                cnt++;
                students[i].sum += students[i].scores[j].value();
                if (students[i].scores[j].value() == maxScores[j]) students[i].perfectNum++;
            }
        }
        if (!cnt) {
           students[i].sum = -1;
        }
        else num++;
    }
    sort(students.begin(), students.end());
    char buf[50];
    int rank = 1;
    int offset = 1;
    const char* format = "%d %05d %d ";
    sprintf(buf, format, rank, students[0].id, students[0].sum);
    cout << buf;
    PrintScores(students[0].scores, K);
    cout << endl;
    for (int i = 1; i < num; ++i) {
        if (students[i - 1].sum == students[i].sum) {
            offset++;
        }
        else {
            rank += offset;
            offset = 1;
        }
        sprintf(buf, format, rank, students[i].id, students[i].sum);
        cout << buf;
        PrintScores(students[i].scores, K);
        cout << endl;
    }
}