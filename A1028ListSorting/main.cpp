#include <bits/stdc++.h>
// Accepted!
using namespace std;

struct Student {
    char name[10];
    int id;
    int grade;
};

bool cmp1(const Student& a, const Student& b) {
    if (a.id < b.id) return true;
    return false;
}

bool cmp2(const Student& a, const Student& b) {
    int ret = strcmp(a.name, b.name);
    if (ret == 0) return cmp1(a, b);
    return ret < 0;
}

bool cmp3(const Student& a, const Student& b) {
    int ret = a.grade - b.grade;
    if (ret == 0) return cmp1(a, b);
    return ret < 0;

}

int main() {
    std::ios::sync_with_stdio(false);
    int N, C;
    cin >> N >> C;
    array<Student, 100000> arr = {};
    for (int i = 0; i < N; ++i) {
        cin >> arr[i].id >> arr[i].name >> arr[i].grade;
    }
    char buf[50];
    switch (C) {
        case 1:
            sort(arr.begin(), arr.begin() + N, cmp1);
            break;
        case 2:
            sort(arr.begin(), arr.begin() + N, cmp2);
            break;
        case 3:
            sort(arr.begin(), arr.begin() + N, cmp3);
            break;
    }
    for (int i = 0; i < N; ++i) {
        sprintf(buf, "%06d %s %d", arr[i].id, arr[i].name, arr[i].grade);
        cout << buf << endl;
    }
    return 0;
}
