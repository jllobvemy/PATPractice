#include <bits/stdc++.h>
// Accepted! Note: Do not use endl
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    char names[40010][5];
    array<vector<char*>, 2600> course2stu;
    int N;
    int K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) {
        char* name = names[i];
        int n;
        cin >> name >> n;
        for (int j = 0; j < n; ++j) {
            int cn;
            cin >> cn;
            course2stu[cn].push_back(name);
        }
    }
    bool firstline = true;
    for (auto i = 1; i <= K; i++) {
        // !! Do not use endl.
        if (firstline) {
            cout << i << " " << course2stu[i].size();
//            printf("%d %d", i, course2stu[i].size());
            firstline = false;
        }
        else {
            cout << "\n" << i << " " << course2stu[i].size();
//            printf("\n%d %d", i, course2stu[i].size());
        }
        if (!course2stu[i].empty())
            cout << "\n";
//            printf("\n");
        sort(course2stu[i].begin(), course2stu[i].end(), [](char *s1, char* s2) {
            return strcmp(s1, s2) < 0;
        });
        bool firstitem = true;
        for (const auto& name: course2stu[i]) {
            if (firstitem) {
                cout << name;
//                printf("%s", name);
                firstitem = false;
            }
            else {
                cout << "\n" << name;
//                printf("\n%s", name);
            }
        }
    }
    return 0;
}
