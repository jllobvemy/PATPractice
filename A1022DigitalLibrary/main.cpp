#include <bits/stdc++.h>
using namespace std;
constexpr string_view NOTFOUND = "Not Found";

void PrintID(int id) {
    char tmp[20];
    sprintf(tmp, "%07d", id);
    cout << tmp << endl;
};

int main() {
    multimap<string, int> title2ID;
    map<string, set<int>> author2ID;
    map<string, set<int>> kw2ID;
    map<string, set<int>> pub2ID;
    map<int, set<int>> year2ID;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int ID;
        cin >> ID;
        cin.get();
        string title;
        getline(cin, title);
        title2ID.emplace(move(title), ID);
        string author;
        getline(cin, author);
        author2ID[author].insert(ID);
        string kws;
        getline(cin, kws);
        stringstream ss(kws);
        string kw;
        while (getline(ss, kw, ' ')) {
            kw2ID[kw].insert(ID);
        }
        string pub;
        getline(cin, pub);
        pub2ID[pub].insert(ID);
        int year;
        cin >> year;
        year2ID[year].insert(ID);
    }
    int queryNum;
    cin >> queryNum;
    cin.get();
    for (int i = 0; i < queryNum; ++i) {
        string tmp;
        getline(cin, tmp);
        int querySort = tmp[0] - '0';
        string queryText = tmp.substr(3, tmp.size() - 3);
        switch (querySort) {
            case 1:  { // Title
                cout << "1: " << queryText << endl;
                auto [b, e] = title2ID.equal_range(queryText);
                if (b == e) cout << NOTFOUND << endl;
                for (auto it = b; it != e; it++) {
                    PrintID(it->second);
                }
                break;
            }
            case 2: { // Author
                cout << "2: " << queryText << endl;
                auto b = author2ID.find(queryText);
                if (b != author2ID.end()) {
                    for (auto e: b->second) {
                        PrintID(e);
                    }
                }
                else
                    cout << NOTFOUND << endl;
                break;
            }
            case 3: { // keyword
                cout << "3: " << queryText << endl;
                auto b = kw2ID.find(queryText);
                if (b != kw2ID.end()) {
                    for (auto e: b->second) {
                        PrintID(e);
                    }
                }
                else {
                    cout << NOTFOUND << endl;
                }
                break;
            }
            case 4: { // pub
                cout << "4: " << queryText << endl;
                auto b = pub2ID.find(queryText);
                if (b != pub2ID.end()) {
                    for (auto e: b->second) {
                        PrintID(e);
                    }
                }
                else {
                    cout << NOTFOUND << endl;
                }
                break;
            }
            case 5: {   // year
                cout << "5: " << queryText << endl;
                int y = stoi(queryText);
                auto b = year2ID.find(y);
                if (b != year2ID.end()) {
                    for (auto e: b->second) {
                        PrintID(e);
                    }
                }
                else {
                    cout << NOTFOUND << endl;
                }
                break;
            }
        }

    }
    return 0;
}
