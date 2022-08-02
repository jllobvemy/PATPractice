#include <bits/stdc++.h>
using namespace std;

struct BigNum {
    string number;
    explicit BigNum(string&& s): number(s) {
    }
    BigNum(BigNum&& bigNum) noexcept : number(move(bigNum.number)) {}
    BigNum(const BigNum& bigNum) noexcept = default;
    BigNum() = default;
    BigNum& operator=(BigNum&& other) {
        number = move(other.number);
        return *this;
    }

    [[nodiscard]]
    unique_ptr<BigNum> get_reverse() const {
        auto ret = make_unique<BigNum>();
        ret->number = number;
        std::reverse(ret->number.begin(), ret->number.end());
        return ret;
    }

    BigNum operator+(const BigNum& other) {
        BigNum ret;
        const string* other_ = &other.number;
        if (this->number.size() >= other.number.size()) {
            ret.number = this->number;
        }
        else {
            ret.number = other.number;
            other_ = &this->number;
        }
        auto char2num = [](char x) {
            return static_cast<uint8_t>(x - '0');
        };
        auto num2char = [](uint8_t num) {
            return static_cast<char>(num + '0');
        };
        auto it1 = ret.number.rbegin();
        auto it2 = other_->rbegin();
        uint8_t j = 0;
        do {
            int8_t tmp = char2num(*it1) + char2num(*it2);
            tmp += j;
            if (tmp > 9) j = 1;
            else j = 0;
            *it1 = num2char(tmp % 10);
            it1++;
            it2++;
            if (it2 == other.number.rend()) {
                if (it1 != ret.number.rend()) {
                    *it1 += j;
                }
                else {
                    ret.number.insert(ret.number.begin(), '1');
                }
                break;
            }
        } while(true);
        return ret;
    }
    friend ostream& operator<<(ostream& o, const BigNum& num) {
        o << num.number;
        return o;
    }

};

bool is_palindromic(const BigNum& num) {
    auto itbegin = num.number.begin();
    auto itend = num.number.end() - 1;
    while (true) {
        if (*itend == *itbegin) {
            itbegin++;
            itend--;
            if (itend == itbegin) return true;
        }
        else {
            return false;
        }
    }

}


int main() {
    string s;
    int N;
    cin >> s >> N;
    BigNum num(move(s));
    int i;
    BigNum tmp;
    for (i = 0; i < N; ++i) {
        tmp = num + *num.get_reverse();
        if (is_palindromic(tmp)) {
            break;
        }
        num = move(tmp);
    }
    cout << i << endl << tmp;
    return 0;
}
