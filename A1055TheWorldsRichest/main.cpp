#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct RichMan {
    int age;
    int worth;
    char name[10];
};
bool cmpName(const RichMan& a, const RichMan& b) {
    if (strcmp(a.name, b.name) < 0) return true;
    return false;
}

bool cmpAgeName(const RichMan& a, const RichMan& b) {
    if (a.age < b.age) return true;
    if (a.age == b.age) return cmpName(a, b);
    return false;
}

bool cmpWorthAge(const RichMan& a, const RichMan& b) {
    if (a.worth > b.worth) return true;
    if (a.worth == b.worth) return cmpAgeName(a, b);
    return false;
}

struct SearchInfo {
    int num, minAge, maxAge;
};

int main() {
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    array<SearchInfo, 1000> searchInfo{};
    vector<RichMan> men(N);
    for (int i = 0; i < N; ++i) {
        cin >> men[i].name >> men[i].age >> men[i].worth;
    }
    for (int i = 0; i < K; ++i) {
        cin >> searchInfo[i].num >> searchInfo[i].minAge >> searchInfo[i].maxAge;
    }
    sort(men.begin(), men.begin() + N, cmpWorthAge);
    char buf[50];
    vector<RichMan> copyList;
    vector<int> copyListLimit(200, 0);
    for (const auto& i: men) {
        if (copyListLimit[i.age] < 100)
        {
            copyList.push_back(i);
            copyListLimit[i.age]++;
        }
    }
    for (int i = 0; i < K; ++i) {
        sprintf(buf, "Case #%d:\n", i + 1);
        cout << buf;
        int count = 0;
        for (const auto& j: copyList) {
            if (j.age >= searchInfo[i].minAge && j.age <= searchInfo[i].maxAge && count < searchInfo[i].num)
            {
                sprintf(buf, "%s %d %d\n", j.name, j.age, j.worth);
                count++;
                cout << buf;
            }
        }
        if (count == 0) {
            sprintf(buf, "None\n");
            cout << buf;
        }
    }
    return 0;
}
