#include <bits/stdc++.h>
// AC!
using namespace std;
int N;
struct Lottery {
    int number;
    int index;
};
map<int, Lottery> m;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int number;
        cin >> number;
        if (m.find(number) != m.end()) {
            m[number].number++;
        }
        else {
            Lottery l;
            l.number = 1;
            l.index = i;
            m[number] = l;
        }
    }
    int min = INT_MAX;
    int minIndex = INT_MAX;
    auto res = m.end();
    for (auto i = m.begin(); i != m.end(); i++) {
        if (i->second.number < min) {
                minIndex = i->second.index;
                min = i->second.number;
                res = i;
        }
        else if (i->second.number == min) {
            if (i->second.index < minIndex) {
                minIndex = i->second.index;
                min = i->second.number;
                res = i;
            }
        }
    }
    if (res->second.number > 1) cout << "None" << endl;
    else cout << res->first << endl;
    return 0;
}
