#include <bits/stdc++.h>
// Accepted!
using namespace std;
vector<vector<int>> split(const vector<int>& v, int Ng) {
    auto ret = vector<vector<int>>();
    if (v.size() <= Ng) {
        ret.push_back(v);
        return ret;
    }
    int newsize = v.size() / Ng == 0 ? v.size() / Ng: v.size() / Ng + 1;
    ret.resize(newsize);
    int x = 1;
    int index = 0;
    for (auto i: v) {
        if (x > Ng) {
            x = 1;
            index++;
        }
        x++;
        ret[index].push_back(i);
    }
    return ret;
}

int main() {
    int Np, Ng;
    cin >> Np >> Ng;
    map<int, int> weights;
    vector<int> order;
    for (int i = 0; i < Np; ++i) {
        int tmp;
        cin >> tmp;
        weights[i] = (tmp);
    }
    for (int i = 0; i < Np; ++i) {
        int tmp;
        cin >> tmp;
        order.push_back(tmp);
    }
    vector<vector<int>> tmp;
    map<int, int> rank;
    vector<vector<int>> res;
    do {
        tmp = split(order, Ng);
        if (tmp.front().size() == 1) {
            res.emplace_back(tmp.front());
            break;
        }
        res.emplace_back();
        order.clear();
        for (auto& t: tmp) {
            auto maxelem = max_element(t.begin(), t.end(), [&weights](auto a, auto b){
                return weights[a] < weights[b];
            });
            if (maxelem == t.end()) continue;
            order.push_back(*maxelem);
            for (auto it = t.begin(); it != t.end(); it++) {
                if (it == maxelem) continue;
                res.back().push_back(*it);
            }
        }
    } while(true);
    int offset = 1;
    for (auto it = res.rbegin(); it != res.rend(); it++) {
        for (auto i: *it) {
            rank[i] = offset;
        }
        offset += it->size();
    }
    bool first = true;
    for (auto i: rank) {
        if (!first) cout << " ";
        else first = false;
        cout << i.second;
    }

    return 0;
}
