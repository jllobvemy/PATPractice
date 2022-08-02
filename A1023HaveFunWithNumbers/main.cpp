#include <bits/stdc++.h>
// Accepted!
using namespace std;

class BigNum {
    using BigNum_t = vector<uint8_t>;
    BigNum_t num;
    int usednumbers[10] = {0};
public:
    explicit BigNum(const string& s){
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            uint8_t used_num = *it - '0';
            num.push_back(used_num);
            usednumbers[used_num]++;
        }
    }
    void doubleBigNum() {
        uint8_t carry = 0;
        for (unsigned char& it : num) {
            uint8_t tmp = it * 2;
            it = tmp % 10;
            it += carry;
            if (tmp > 9) {
                carry = 1;
            }
            else {
                carry = 0;
            }
        }
        if (carry == 1) num.push_back(1);
    }
    [[nodiscard]]
    bool allInUsedNumbers() {
        for (auto n: num) {
            usednumbers[n]--;
        }
        for (auto n: usednumbers) {
            if (n != 0) return false;
        }
        return true;
    }
    friend ostream& operator<<(ostream& o, const BigNum& b) {
        for (auto it = b.num.crbegin(); it != b.num.crend(); it++) {
            o << +(*it);
        }
        return o;
    }
};

int main() {
    string buf;
    cin >> buf;
    BigNum n(buf);
    n.doubleBigNum();
    if (n.allInUsedNumbers()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << n;
    return 0;
}
