#include <bits/stdc++.h>
// Accepted!
using namespace std;

int main() {
    string shop, needColor;
    cin >> shop >> needColor;
    map<char, int> shopMap;
    for (auto c: shop) {
        shopMap[c]++;
    }
    int missing = 0;
    bool haveall = true;
    for (auto c: needColor) {
        if (shopMap.find(c) == shopMap.end() || shopMap[c] == 0) {
            haveall = false;
            missing++;
        }
        else {
            shopMap[c]--;
        }
    }
    if (haveall) {
        cout << "Yes " << shop.size() - needColor.size();
    }
    else {
        cout << "No " << missing;
    }
    return 0;
}
