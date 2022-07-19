#include <bits/stdc++.h>
// not ac, I cannot understand the question.
using namespace std;

int N, K;  // N <= 10000 number of record; K <= 80000 the number of queries.
struct Time {
    int hour = 0, minute = 0, second = 0;
    bool operator<(const Time& b) const {
        return Time2Seconds(*this) < Time2Seconds(b);
    }
    bool operator>(const Time& b) const {
        return Time2Seconds(*this) > Time2Seconds(b);
    }
    inline static int Time2Seconds(const Time& t) {
        return t.hour * 3600 + t.minute * 60 + t.second;
    }
    static Time Seconds2Time(int s) {
        Time t;
        t.hour = s / 3600;
        s %= 3600;
        t.minute = s / 60;
        s %= 60;
        t.second = s;
        return t;
    }
};

struct Car {
    Time in;
    Time out;
    int duration;
    char plate[10];
};
struct CarCmp {
    bool operator() (const Car& a, const Car& b) const {
        return a.out < b.out;
    }
};
struct CarRecord {
    set<Time> in;
    set<Time> out;
};
map<string, CarRecord> records;
vector<Time> queries;
vector<Car> querySet;

int main() {
    char buff[50];
    Time t;
    char strflag[10];
    char plate[10];
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        cin.getline(buff, 50);
        sscanf(buff, "%s %d:%d:%d %s", plate, &t.hour, &t.minute, &t.second, strflag);
        if (strflag[0] == 'i') {
            records[plate].in.insert(t);
        }
        else {
            records[plate].out.insert(t);
        }
    }
    for (int i = 0; i < K; ++i) {
        cin.getline(buff, 50);
        sscanf(buff, "%d:%d:%d", &t.hour, &t.minute, &t.second);
//        queries[i] = t;
        queries.push_back(t);
    }
    for (auto& record: records) {
        for (const auto& in: record.second.in) {
            int min = INT_MAX;
            auto x = record.second.out.end();
            for (auto i = record.second.out.begin(); i != record.second.out.end(); ++i) {
                int time = Time::Time2Seconds(*i);
                if (time < min) {
                    x = i;
                    min = time;
                }
            }
            if (x != record.second.out.end()) {
                Car c;
                c.in = in;
                c.out = *x;
                c.duration = Time::Time2Seconds(c.out) - Time::Time2Seconds(c.in);
                strcpy(c.plate, record.first.c_str());
                querySet.push_back(c);
                record.second.out.erase(x);
            }
        }
    }
    for (const auto& query: queries) {
        int ans = 0;
        for (const auto&car: querySet) {
            if (car.out > query && car.in < query)
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
