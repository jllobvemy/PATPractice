#include <bits/stdc++.h>
using namespace std;
struct Score {
    int userNumber;
    array<int, 5> scores = {-2, -2, -2, -2, -2};
    int sum = -5;
    bool flag = false;
};
int N, K, M;
array<Score, 10000> users;
array<int, 5> maxScore;
int score_sum(Score& a) {
    int sum = 0;
    for (int i = 0; i < K; ++i) {
        if (a.scores[i] > 0)
        {
            sum += a.scores[i];
            a.flag = true;
        }
    }
    return sum;
}
bool cmp(Score& a, Score& b) {
    int res1, res2;
    if (a.sum < 0){
        res1 = score_sum(a);
        a.sum = res1;
    }
    else res1 = a.sum;
    if (b.sum < 0) {
        res2 = score_sum(b);
        b.sum = res2;
    }
    else res2 = b.sum;
    if (res1 > res2) return true;
    if (res1 == res2) {
        res1 = res2 = 0;
        for (int i = 0; i < K; ++i) {
            if (a.scores[i] == maxScore[i])
                res1++;
        }
        for (int i = 0; i < K; ++i) {
            if (b.scores[i] == maxScore[i])
                res2++;
        }
        if (res1 > res2) return true;
        if (res1 == res2) return a.userNumber < b.userNumber;
    }
    return false;
}

int main() {
    cin >> N >> K >> M;
    for (int i = 0; i < K; ++i) {
        cin >> maxScore[i];
    }
    for (int i = 0; i < M; ++i) {
        int userNum, problemNum, score;
        cin >> userNum >> problemNum >> score;
        if (users[userNum - 1].scores[problemNum - 1] < score) {
            users[userNum - 1].scores[problemNum - 1] = score;
            users[userNum - 1].userNumber = userNum;
        }
    }
    sort(users.begin(), users.begin() + N, cmp);
    char buf[50];
    sprintf(buf, "%05d", users[0].userNumber);
    cout << 1 << " " << buf << " " << users[0].sum << " ";
    for (int j = 0; j < K; ++j) {
        if (users[0].scores[j] >= 0)
            cout << users[0].scores[j];
        else if (users[0].scores[j] == -2)
            cout << "-";
        else cout << "0";
        if (j != K - 1) cout << " ";
    }
    int rank = 1, offset = 1;
    if (users[1].flag)
        cout << endl;
    for (int i = 1; i < N; ++i) {
        if (!users[i].flag) continue;
        sprintf(buf, "%05d", users[i].userNumber);
        if (users[i].sum == users[i - 1].sum) {
            offset++;
        }
        else {
            rank += offset;
            offset = 1;
        }
        cout << rank << " " << buf << " " << users[i].sum << " ";
        for (int j = 0; j < K; ++j) {
            if (users[i].scores[j] >= 0)
                cout << users[i].scores[j];
            else if (users[i].scores[j] == -2)
                cout << "-";
            else cout << "0";
            if (j != K - 1) cout << " ";
        }
        if (i != N - 1) cout << endl;
    }
    return 0;
}
