#include <bits/stdc++.h>
// Accepted!
using namespace std;
int turn;
array<string, 54> cards;
array<string, 54> fillCard() {
    using cards_t = array<string, 54>;
    char cardType[] = {'S', 'H', 'C', 'D'};
    cards_t ret;
    for (auto j = 0; j < 4; j++) {
        for (int i = 0; i < 13; ++i) {
            char buf[10] = {};
            sprintf(buf, "%c%d", cardType[j], i + 1);
            ret[13 * j + i] = buf;
        }
    }
    ret[52] = "J1";
    ret[53] = "J2";
    return ret;
}

void makeTurn(vector<int>& order) {
    auto ret = array<string, 54>();
    for (int i = 0; i < order.size(); ++i) {
        ret[order[i] - 1] = cards[i];
    }
    for (int i = order.size(); i < 54; ++i) {
        ret[i] = cards[i];
    }
    cards = ret;
}


int main() {
    cards = fillCard();
    cin >> turn;
    string s;
    cin.get();
    getline(cin, s);
    vector<int> order;
    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, ' ')) {
        order.push_back(stoi(tmp));
    }
    while(turn--) {
        makeTurn(order);
    }
    bool first = true;
    for (auto& i: cards) {
        if (first) {
            first = false;
            cout << i;
        }
        else cout << " " << i;
    }
    return 0;
}
