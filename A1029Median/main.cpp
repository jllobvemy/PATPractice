#include <bits/stdc++.h>
// Accepted! bad way.
using namespace std;
int N1, N2;
set<long> list0;
vector<long> list1;
vector<long> list2;

int main() {
    ios::sync_with_stdio(false);
    cin >> N1;
//    list1.reserve(N1);
    for (int i = 0; i < N1; ++i) {
        int tmp;
        cin >> tmp;
//        list1.push_back(tmp);
        list0.insert(tmp);
    }
    cin >> N2;
//    list2.reserve(N2);
    for (int i = 0; i < N2; ++i) {
        int tmp;
        cin >> tmp;
//        list2.push_back(tmp);
        list0.insert(tmp);
    }
    int total = N1 + N2;
    int mid;
    if (total % 2) {
        mid = (total + 1) / 2;
    }
    else {
        mid = total / 2;
    }
    auto it = list0.begin();
    advance(it, mid - 1);
    cout << *it;
    return 0;
    if (N1 == 0) {
        cout << list2[mid - 1];
        return 0;
    }
    if (N2 == 0) {
        cout << list1[mid - 1];
        return 0;
    }
    int n = 0;
    auto it1 = list1.begin();
    auto it2 = list2.begin();
    while (true) {
        while (*it1 >= *it2) {
            if (n == mid - 1) {
                cout << *it2;
                return 0;
            }
            it2++;
            n++;
        }
        if (n == mid - 1) {
            cout << *it1;
            return 0;
        }
        it1++;
        n++;
    }
}
