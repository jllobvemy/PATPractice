#include <bits/stdc++.h>
// Accepted!
using namespace std;
struct MC {
    double inventory;
    double price;
    double ave;
    bool operator<(const MC& other) const {
        return ave > other.ave;
    }
};

int main() {
    int N;
    double Demand;
    vector<MC> mooncakes;
    cin >> N >> Demand;
    if (N == 0 || Demand == 0) return 1;
    mooncakes.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> mooncakes[i].inventory;
        if (mooncakes[i].inventory == 0) return 1;
    }
    for (int i = 0; i < N; ++i) {
        cin >> mooncakes[i].price;
        mooncakes[i].ave = mooncakes[i].price / mooncakes[i].inventory;
    }
    stable_sort(mooncakes.begin(), mooncakes.end());
    double sum = 0;
    double sumprice = 0;
    int index = 0;
    while (sum != Demand) {
        if (sum + mooncakes[index].inventory >= Demand) {
            double diff = Demand - sum;
            sumprice += diff * mooncakes[index].ave;
            sum += diff;
        }
        else {
            sumprice += mooncakes[index].price;
            sum += mooncakes[index].inventory;
        }
        index++;
        if (index >= mooncakes.size()) break;
    }
    char buf[20];
    sprintf(buf, "%.2f\n", sumprice);
    cout << buf;
    return 0;
}
