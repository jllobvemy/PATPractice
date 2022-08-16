#include <bits/stdc++.h>
// Accepted!
using namespace std;
int N;

struct Time {
    int hour = 0, minute = 0, second = 0;
    Time() = default;
    Time(int h, int m, int s): hour(h), minute(m), second(s) {}
    bool operator<(const Time& other) const {
        if (hour < other.hour) {
            return true;
        }
        else if (hour == other.hour) {
            if (minute < other.minute) {
                return true;
            } else if (minute == other.minute) {
                if (second < other.second){
                    return true;
                }
            }
        }
        return false;
    }
    bool operator>(const Time& other) const {
        return !(*this < other);
    }
};
struct Person {
    Time in, out;
    char name[20];
};

bool cmp1(Person& a, Person& b) {
    return a.in < b.in;
}
bool cmp2(Person& a, Person& b) {
    return a.out > b.out;
}

int main() {
    vector<Person> persons;
    cin >> N;
    persons.resize(N);
    cin.get();
    for (int i = 0; i < N; ++i) {
        string tmp;
        getline(cin, tmp);
        sscanf(tmp.c_str(), "%s %d:%d:%d %d:%d:%d", persons[i].name,
               &persons[i].in.hour, &persons[i].in.minute, &persons[i].in.second,
               &persons[i].out.hour, &persons[i].out.minute, &persons[i].out.second);
    }
    sort(persons.begin(), persons.end(), cmp1);
    cout << persons.begin()->name;
    sort(persons.begin(), persons.end(), cmp2);
    cout << " " << persons.begin()->name;
    return 0;
}
