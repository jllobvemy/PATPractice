#include <bits/stdc++.h>
// not completed.
using namespace std;
double Cmax; // tank capacity
double D; // distance
double Davg; // distance/unit
int N;
map<int, float> stations;

int main() {
    cin >> Cmax >> D >> Davg >> N;
    double maxDistance = Cmax * Davg;
    for (int i = 0; i < N; ++i) {
        float price;
        int dis;
        cin >> price >> dis;
        stations.insert({dis, price});
    }
    float currentPrice = 0.0f;
    double currentDis = 0;
    double currentGas = 0;
    while (currentDis < D) {

    }
    for (auto a = stations.begin(); a != stations.end(); a++) {
        int dis = 0;
        for (auto b = next(a); b != stations.end(); ++b) {
            if (b->first - a->first > maxDistance) {
                currentDis += currentGas * Davg;
                goto end;
            }
            if (a->second > b->second) {

            }
        }

    }
    end:;

    return 0;
}
