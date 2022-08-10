#include <bits/stdc++.h>
// Accepted!
using namespace std;
int N;
vector<int> raw;
vector<int> mid;

void PrintVector(const vector<int>& a) {
    bool first = true;
    for (auto e: a) {
        if (first) {
            cout << e;
            first = false;
        }
        else {
            cout << " " << e;
        }
    }
}

int main() {
    cin >> N;
    raw.reserve(N);
    mid.reserve(N);
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        raw.push_back(tmp);
    }
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        mid.push_back(tmp);
    }
    vector<int> heaptmp = raw;
    make_heap(heaptmp.begin(), heaptmp.end(), less<>());
    bool isheapSort = false;
    int i = 0;
    for (i = 0; i < heaptmp.size(); ++i) {
        if (mid == heaptmp) {
            isheapSort = true;
            break;
        }
        pop_heap(heaptmp.begin(), heaptmp.end() - i);
    }
    if (isheapSort) {
        cout << "Heap Sort" << endl;
        pop_heap(heaptmp.begin(), heaptmp.end() - i);
        PrintVector(heaptmp);
        return 0;
    }
    else {
        cout << "Insertion Sort" << endl;
        int j = 0;
        for (j = 2; j < raw.size(); ++j) {
            sort(raw.begin(), raw.begin() + j);
            if (raw == mid) break;
        }
        sort(raw.begin(), raw.begin() + j + 1);
        PrintVector(raw);
    }
    return 0;
}
