#include <bits/stdc++.h>
// Accepted! The code is rubbish.
using namespace std;
int N;
vector<int> raw_data;
vector<int> partial_sort_data;
vector<int> answer;


bool InsertSort(vector<int> a) { // must copy
    bool finish = false;
    for (auto it = next(a.begin()); it != a.end(); it++) {
        for (auto it2 = a.begin(); it2 != it; it2++) {
            if (*it < *it2) {
                if (a == partial_sort_data) finish = true;
                auto tmp = *it;
                a.erase(it);
                a.insert(it2, tmp);
                break;
            }
        }
        if (finish) {
            answer = a;
            return true;
        }
    }
    return false;
}

bool MergeSort(vector<int>& a) { // reference
    int len = 2;
    bool finish = false;
    while (true) {
        auto it = a.begin();
        while (it < a.end()) {
            sort(it, (it + len) < a.end() ? it + len : a.end());
            it += len;
        }
        len *= 2;
        if (finish || len > a.size()) {
            break;
        }
        if (a == partial_sort_data) finish = true;
    }
    return true;
}


int main() {
    cin >> N;
    raw_data.reserve(N);
    partial_sort_data.reserve(N);
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        raw_data.push_back(tmp);
    }
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        partial_sort_data.push_back(tmp);
    }
    auto ans = InsertSort(raw_data);
    if (ans) {
        bool first = true;
        cout << "Insertion Sort" << endl;
        for (auto x: answer) {
            if (first) {
                first = false;
                cout << x;
            }
            else {
                cout << " " << x;
            }
        }
    }
    else {
        bool first = true;
        cout << "Merge Sort" << endl;
        MergeSort(raw_data);
        for (auto x: raw_data) {
            if (first) {
                first = false;
                cout << x;
            }
            else {
                cout << " " << x;
            }
        }
    }
    return 0;
}
