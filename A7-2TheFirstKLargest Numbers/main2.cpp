#include <iostream>
#include <random>
using namespace std;
constexpr int MAXLEN = 1000000;

int main()
{
    freopen("input.txt", "w", stdout);
    cout << MAXLEN << " " << 5 << endl;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution dist6(INT_MIN + 1,INT_MAX); // distribution in range [1, 6]
    for (int i = 0; i < MAXLEN; ++i) {
        std::cout << dist6(rng) << " ";
    }
}