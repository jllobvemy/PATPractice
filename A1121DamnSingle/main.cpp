#include <bits/stdc++.h>
// Accepted!
using namespace std;
map<int, int> couples1;
map<int, int> couples2;

int findCouple(int a) {
    if (couples1.find(a) != couples1.end()) return couples1[a];
    if (couples2.find(a) != couples2.end()) return couples2[a];
    return -1;
}

map<int, optional<list<int>::iterator>> people;

int main() {
    int N;
    cin >> N;
    if (N == 0) return 1;
    for (int i = 0; i < N; ++i) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        couples1[tmp1] = tmp2;
        couples2[tmp2] = tmp1;
    }
    int K;
    cin >> K;
    list<int> customers;
    for (int i = 0; i < K; ++i) {
        int tmp;
        cin >> tmp;
        customers.push_back(tmp);
        people[tmp] = prev(customers.end());
        int peer = findCouple(tmp);
        if (people[peer].has_value()) {
            customers.erase(people[peer].value());
            customers.pop_back();
        }
    }
    customers.sort();

    cout << customers.size() << endl;
    bool first = true;
    char buf[50];
    for (auto e: customers) {
        if (e == -1) return 1;
        sprintf(buf, "%05d", e);
        if (first)
            first = false;
        else cout << " ";
        cout << buf;
    }
    return 0;
}
