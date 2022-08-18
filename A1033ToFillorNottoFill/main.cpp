#include <bits/stdc++.h>
// Accepted!
using namespace std;
double CMax, D, Dave;
int N;

struct Station {
    double dis;
    double price;
    bool operator<(const Station& other) const {
        return dis < other.dis;
    }
    Station(int dis, double price): price(price), dis(dis) {}
};

int main() {
    const char* format = "The maximum travel distance = %.2f";
    char buf[100];
    cin >> CMax >> D >> Dave >> N;
    vector<Station> q;
    q.emplace_back(D, 0);
    for (int i = 0; i < N; ++i) {
        double p;
        double d;
        cin >> p >> d;
        q.emplace_back(d, p);
    }
    sort(q.begin(), q.end());
    if (q.front().dis != 0) {
        sprintf(buf, format, 0);
        cout << buf;
        return 0;
    }
    double curtPosi = 0, maxDis = 0, curtPrice = q[0].price, totalPrice = 0, leftDis = 0;
    while (curtPosi < D) {
        maxDis = curtPosi + Dave * CMax;
        double minPrice = DBL_MAX, minPriceDis;
        bool flag = false;
        for (int i = 1; q[i].dis <= maxDis; ++i) {
            if (q[i].dis <= curtPosi) continue;
            if (q[i].price <= curtPrice) {
                totalPrice += (q[i].dis - curtPosi - leftDis) * curtPrice / Dave;
                leftDis = 0;
                curtPrice = q[i].price;
                curtPosi = q[i].dis;
                flag = true;
                break;
            }
            if (q[i].price < minPrice) {
                minPrice = q[i].price;
                minPriceDis = q[i].dis;
            }
        }
        if (!flag) {
            if (minPrice == DBL_MAX) {
                curtPosi += CMax * Dave;
                sprintf(buf, format, curtPosi);
                cout << buf;
                return 0;
            }
            totalPrice += (curtPrice * (CMax - leftDis / Dave));
            leftDis = CMax * Dave + curtPosi - minPriceDis;
            curtPrice = minPrice;
            curtPosi = minPriceDis;
        }
    }
    printf("%.2f", totalPrice);
}
