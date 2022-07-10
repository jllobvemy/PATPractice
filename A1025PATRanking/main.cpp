#include <bits/stdc++.h>
// ACCEPTED!!
using namespace std;
struct Score{
    int score, location, localRank;
    unsigned long  number;
    Score(unsigned long n, int s, int l) : number(n), score(s), location(l) {}
    bool operator<(const Score& s2) const {
        if (this->score < s2.score) {
            return false;
        }
        if (this->score == s2.score) {
            if (this->number > s2.number) {
                return false;
            }
            return true;
        }
        return true;
    }
};
int N, TOTAL = 0;
vector<Score> scoreList;
vector<int> localRank;


int main() {
    cin >> N;
    localRank.resize(N);
    vector<int> localRankOff;
    localRankOff.resize(N);

    for (int i = 0; i < N; ++i) {
        localRank[i] = 0;
        localRankOff[i] = 0;
    }
    int loc = 1;
    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        for (int j = 0; j < K; ++j) {
            unsigned long num;
            short score;
            cin >> num >> score;
            scoreList.emplace_back(num, score, loc);
            TOTAL++;
        }
        loc++;
    }
    sort(scoreList.begin(), scoreList.end());
    for (auto i = scoreList.begin(); i < scoreList.end(); ++i) {
        i->localRank = localRank[i->location - 1] + 1;
        if ([i, end = scoreList.end()](){
            for (auto j = i + 1; j < end; ++j) {
                if (i->location == j->location && i->score == j->score)
                    return true;
            }
            return false;
        }()) {
            localRankOff[i->location - 1]++;
        }
        else {
            localRank[i->location - 1] += localRankOff[i->location - 1] + 1;
            localRankOff[i->location - 1] = 0;
        }
    }
    int rankOff = 0;
    int currentRank = 1;
    cout << TOTAL << endl;
    for (auto i = scoreList.begin(); i < scoreList.end(); ++i) {
        cout << i->number << " " << currentRank << " " << i->location << " " << i->localRank;
        if (i + 1 != scoreList.end()) cout << endl;
        if ((i + 1)->score == i->score) rankOff++;
        else {
            currentRank += rankOff + 1;
            rankOff = 0;
        }
    }
    return 0;
}
