#include <bits/stdc++.h>
// Don't understand the question. Again.
using namespace std;
int N, K;
int Time2Second(const string& t) {
    int hh, mm, ss;
    sscanf(t.c_str(), "%d:%d:%d", &hh, &mm, &ss);
    return hh * 3600 + mm * 60 + ss;
}

string Second2Time(int s) {
    char buf[50];
    int hh = s / 3600;
    s %= 3600;
    int mm = s / 60;
    s %= 60;
    int ss = s;
    sprintf(buf, "%02d:%02d:%02d", hh, mm, ss);
    return buf;
}

struct CarRecord {
    priority_queue<int> in;
    priority_queue<int> out;
//    vector <int> in;
//    vector <int> out;
};

int main() {
    cin >> N >> K;
    map<string, CarRecord> carRecords;
    for (int i = 0; i < N; ++i) {
        string plate, time, status;
        cin >> plate >> time >> status;
        if (status == "in") {
            carRecords[plate].in.push(Time2Second(time));
        }
        else {
            carRecords[plate].out.push(Time2Second(time));
        }
    }
    int maxlen = -1;
    vector<pair<int, int>> records;
    map<string, int> ansCars;
    for (auto &[plate, record]: carRecords) {
        while (!record.in.empty() && !record.out.empty()) {
//            int in = record.in.front(), out = record.out.front();
//            record.in.erase(record.in.begin());
//            record.out.erase(record.out.begin());
            int in = record.in.top(), out = record.out.top();
            if (in > out) return 1;
            record.out.pop();
            record.in.pop();
            ansCars[plate] += out - in;
            records.emplace_back(in, out);
        }
    }
    sort(records.begin(), records.end());
    for (int i = 0; i < K; ++i) {
        string query;
        cin >> query;
        int time = Time2Second(query);
        int cnt = 0;
        for (auto &[a, b]: records){
            if (time > a && time < b) {
                cnt++;
            }
            if (time < a) break;
        }
        cout << cnt << '\n';
    }
    int maxtime = -1;
    vector<string> ansTime;
    for (auto &[plate, time]: ansCars) {
        if (time > maxtime) {
            maxtime = time;
            ansTime.clear();
            ansTime.push_back(plate);
        }
        else if (time == maxtime) {
            ansTime.push_back(plate);
        }
    }
    sort(ansTime.begin(), ansTime.end());
    for (auto& s:ansTime) {
        cout << s << ' ';
    }
    cout << Second2Time(maxtime);
}