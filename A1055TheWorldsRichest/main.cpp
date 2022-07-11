#include <bits/stdc++.h>
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

bool cmpWorthName(const RichMan& a, const RichMan& b) {
    if (a.worth > b.worth) return true;
    if (a.worth == b.worth) return cmpName(a, b);
    return false;
}
bool cmpWorthAge(const RichMan& a, const RichMan& b) {
    if (a.worth > b.worth) return true;
    if (a.worth == b.worth) return cmpAgeName(a, b);
    return false;
}

bool cmpAgeWorth(const RichMan& a, const RichMan& b) {
    if (a.age < b.age) return true;
    if (a.age == b.age) return cmpWorthName(a, b);
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
    sort(men.begin(), men.begin() + N, cmpAgeWorth);
    char buf[50];
    vector<RichMan> copyList(N);
    for (int i = 0; i < K; ++i) {
        sprintf(buf, "Case #%d:\n", i + 1);
        cout << buf;
        RichMan tmp;
        tmp.age = searchInfo[i].minAge;
//        strcpy(tmp.name, "A");
//        auto lower = lower_bound(men.begin(), men.begin() + N, tmp, cmpAgeWorth);
        auto lower = find_if(men.begin(), men.end(), [&tmp](const RichMan& man) {
            return man.age >= tmp.age;
        });
        tmp.age = searchInfo[i].maxAge;
//        strcpy(tmp.name, "00000000");
        auto upper = find_if(men.rbegin(), men.rend(), [&tmp](const RichMan& man) {
            return man.age <= tmp.age;
        }).base();
        if (upper == men.rend().base() || lower == men.end()) {
            if (upper->age >= searchInfo[i].minAge && upper->age <= searchInfo[i].maxAge) {
                sprintf(buf, "%s %d %d\n", lower->name, lower->age, lower->worth);
            }
            else {
                sprintf(buf, "None\n");
            }
            cout << buf;
            continue;
        }
        if (upper != men.end()) upper++;
        int num = upper - lower;
        copy(lower, lower + num, copyList.begin());
        sort(copyList.begin(), copyList.begin() + num, cmpWorthAge);
        for (int j = 0; j < searchInfo[i].num && j < num; ++j) {
            sprintf(buf, "%s %d %d\n", copyList[j].name, copyList[j].age, copyList[j].worth);
            cout << buf;
        }
    }
    return 0;
}
