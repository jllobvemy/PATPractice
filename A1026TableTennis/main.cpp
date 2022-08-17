#include <bits/stdc++.h>
// Not complete.
using namespace std;
int N, TableCount, VipTableCount;
int String2Second(const string& time) {
    int ret = 0;
    int hh, mm, ss;
    sscanf(time.c_str(), "%d:%d:%d", &hh, &mm, &ss);
    ret += ss;
    ret += mm * 60;
    ret += hh * 3600;
    return ret;
}

int Second2Minute(int s) {
    return s / 60;
}


struct Person {
    int during;
    int comingTime;
    bool vip;
};

struct Table {
    int end = 8 * 3600;
    bool vip = false;
};

int main() {
    cin >> N;
    vector<Person> persons;
    for (int i = 0; i < N; ++i) {
        string time;
        int during;
        bool vip;
        cin >> time >> during >> vip;
        Person tmp{};
        tmp.during = during;
        tmp.comingTime = String2Second(time);
        tmp.vip = vip;
        persons.push_back(tmp);
    }
    cin >> TableCount >> VipTableCount;
    vector<Table> tables;
    tables.resize(TableCount);
    for (int i = 0; i < VipTableCount; ++i) {
        int tmp;
        cin >> tmp;
        tables[tmp].vip = true;
    }
    sort(persons.begin(), persons.end(), [](auto& a, auto& b) {
        return a.comingTime < b.comingTime;
    });
    while (!persons.empty()) {
        auto& p = persons.front();
        int mintime = INT_MAX;
        Table* selectedTable = nullptr;
        if (p.vip) {
            for (auto& table: tables) {
                if (mintime < table.end && table.vip && table.end < p.comingTime) {
                    mintime = table.end;
                    selectedTable = &table;
                }
            }
        }
        if (!selectedTable) {
            for (auto & table: tables) {
                if (mintime < table.end) {
                    mintime = table.end;
                    selectedTable = &table;
                    break;
                }
            }
        }


    }
    return 0;
}
