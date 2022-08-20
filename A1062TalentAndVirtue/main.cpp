#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct Person {
    int talent;
    int virtue;
    string id;
    int total;
    bool operator<(const Person& other) const {
        if (total > other.total) return true;
        else if (total == other.total) {
            if (virtue > other.virtue) return true;
            else if (virtue == other.virtue)
                return id < other.id;
        }
        return false;
    }
};

int main() {
    int N, H, L;
    vector<Person> sages;
    vector<Person> noblemen;
    vector<Person> foolmen;
    vector<Person> other;
    cin >> N >> L >> H;
    for (int i = 0; i < N; ++i) {
        Person tmp;
        cin >> tmp.id >> tmp.virtue >> tmp.talent;
        tmp.total = tmp.virtue + tmp.talent;
        if (tmp.talent >= L && tmp.virtue >= L) {
            if (tmp.talent >= H && tmp.virtue >= H) {
                sages.push_back(tmp);
            }
            else if (tmp.talent < H && tmp.virtue >= H) {
                noblemen.push_back(tmp);
            }
            else if (tmp.talent < H && tmp.virtue < H && tmp.virtue >= tmp.talent) {
                foolmen.push_back(tmp);
            }
            else {
                other.push_back(tmp);
            }
        }
    }
    sort(sages.begin(), sages.end());
    sort(noblemen.begin(), noblemen.end());
    sort(foolmen.begin(), foolmen.end());
    sort(other.begin(), other.end());
    int sum = sages.size() + noblemen.size() + foolmen.size() + other.size();
    cout << sum << endl;
    char buf[50];
    for (auto& i: sages) {
        sprintf(buf, "%s %d %d\n", i.id.c_str(), i.virtue, i.talent);
        cout << buf;
    }
    for (auto& i: noblemen) {
        sprintf(buf, "%s %d %d\n", i.id.c_str(), i.virtue, i.talent);
        cout << buf;
    }
    for (auto& i: foolmen) {
        sprintf(buf, "%s %d %d\n", i.id.c_str(), i.virtue, i.talent);
        cout << buf;
    }
    for (auto& i: other) {
        sprintf(buf, "%s %d %d\n", i.id.c_str(), i.virtue, i.talent);
        cout << buf;
    }
    return 0;
}
