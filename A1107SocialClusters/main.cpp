#include <bits/stdc++.h>
// Accepted!
using namespace std;
array<int, 1001> hobbies;
array<int, 1001> persons;

int findFather(int index) {
    if (hobbies[index] == index) return index;
    else {
        hobbies[index] = findFather(hobbies[index]);
        return hobbies[index];
    }
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        hobbies[faB] = faA;
    }
}

int main() {
    for (int i = 0; i <= 1000; ++i) {
        hobbies[i] = i;
    }
    for (int i = 0; i <= 1000; ++i) {
        persons[i] = 0;
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int num;
        scanf("%d: ", &num);
        vector<int> hobbytmp;
        for (int j = 0; j < num; ++j) {
            int tmp;
            cin >> tmp;
            hobbytmp.push_back(tmp);
        }
        if (num > 1) {
            for (int j = 1; j < hobbytmp.size(); ++j) {
                Union(hobbytmp[0], hobbytmp[j]);
            }
        }
        persons[findFather(hobbytmp[0])]++;
    }
    vector<int> ans(1001, 0);
    for (int i = 1; i <= 1000; i++) {
        ans[findFather(i)] += persons[i];
    }
    sort(ans.begin(), ans.end(), greater<>());
    int num = 0;
    for (auto e: ans) {
        if (e != 0) {
            num++;
        } else break;
    }
    cout << num << endl;
    bool first = true;
    for (int i = 0; i < num; ++i) {
        if (first) {
            cout << ans[i];
            first = false;
        }
        else {
            cout << " " << ans[i];
        }
    }
    return 0;
}
