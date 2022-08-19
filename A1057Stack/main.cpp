#include <bits/stdc++.h>
// Not accepted.
using namespace std;

void printInvalid() {
    cout << "Invalid\n";
}
void printValue(int i) {
    cout << i << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    vector<int> s;
    vector<short> s2;
    s.reserve(10010);
    s2.reserve(10010);
    int N;
    string command;
    cin >> N;
    cin.get();
    for (int i = 0; i < N; ++i) {
        getline(cin, command);
        if (command[1] == 'e') { // PeekMedian
            if (s.empty()) {
                printInvalid();
            }
            else {
                auto mid = (s.size() + 1) / 2;
                sort(s2.begin(), s2.end());
                printValue(s2[mid - 1]);
            }
        }
        if (command[1] == 'o') { // Pop
            if (s.empty()) {
                printInvalid();
            }
            else {
                printValue(s.back());
                s.pop_back();
                s2.pop_back();
            }
        }
        if (command[1] == 'u') { // Push
            int v = stoi(command.substr(4, command.size() - 4));
            s.push_back(v);
            s2.push_back(v);
        }
    }
    return 0;
}
