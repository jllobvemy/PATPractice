#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct Person {
    int height;
    string name;
    bool operator<(const Person& other) const {
        if (height > other.height) {
            return true;
        } else if (height == other.height) {
            return name < other.name;
        }
        return false;
    }
};

int main() {
    int N, K;
    vector<Person> persons;
    cin >> N >> K;
    persons.reserve(N);
    for (int i = 0; i < N; ++i) {
        Person tmp;
        cin >> tmp.name >> tmp.height;
        persons.push_back(tmp);
    }
    sort(persons.begin(), persons.end());
    int rowNum = floor(N * 1.0 / K);
    int topRowNum = N - rowNum * (K - 1);
    vector<int> rowNums {topRowNum};
    for (int i = 0; i < K - 1; ++i) {
        rowNums.push_back(rowNum);
    }
    int index = 0;
    vector<vector<string>> ans;
    for (int i = 0; i < K; ++i) {
        int posi = 1;
        bool finishMid = false;
        vector<string> tmp;
        tmp.resize(rowNums[i]);
        int mid;
        mid = floor(rowNums[i] * 1.0 / 2);
        tmp[mid] = persons[index++].name;
        bool breakflag = true;
        while (true) {
            breakflag = true;
            int j = mid - posi;
            if (j >= 0) {
                tmp[j] = persons[index++].name;
                breakflag = false;
            }
            j = mid + posi;
            if (j < rowNums[i]) {
                tmp[j] = persons[index++].name;
                breakflag = false;
            }
            posi++;
            if (breakflag) break;
        }
        ans.push_back(tmp);
    }
    for (auto& e: ans) {
        bool first = true;
        for (auto& n: e) {
            if (first) {
                first = false;
                cout << n;
            }
            else {
                cout << " " << n;
            }
        }
        cout << endl;
    }
    return 0;
}
