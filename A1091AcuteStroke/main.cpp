#include <bits/stdc++.h>
// Accepted!
using namespace std;

struct Pixel {
    bool stroke = false;
    bool visited = false;
    explicit Pixel(bool stroke): stroke(stroke) {}
};
vector<vector<vector<Pixel>>> datas;
int M, N, L, T;
bool Valid(int floor, int row, int col) {
    if (floor >= L || row >= M || col >= N || floor < 0 || row < 0 || col < 0 || datas[floor][row][col].visited)
        return false;
    return true;
}
int COL[] = {1, -1, 0, 0, 0, 0};
int ROW[] = {0, 0, -1, 1, 0, 0};
int FLOOR[] = {0, 0, 0, 0, 1, -1};
int findVolume(int floor, int row, int col) {
    int tsum = 0;
    queue<tuple<int, int, int>> q;
    q.emplace(floor, row, col);
    datas[floor][row][col].visited = true;
    while (!q.empty()) {
        auto [floor, row, col] = q.front();
        q.pop();
        tsum++;
        for (int i = 0; i < 6; ++i) {
            auto [newZ, newX, newY] = make_tuple(floor + FLOOR[i], row + ROW[i], col + COL[i]);
            if (Valid(newZ, newX, newY) && datas[newZ][newX][newY].stroke) {
                datas[newZ][newX][newY].visited = true;
                q.emplace(newZ, newX, newY);
            }
        }
    }
    return tsum;
}

int main() {
    cin >> M >> N >> L >> T;
    for (int i = 0; i < L; ++i) {
        vector<vector<Pixel>> slicetmp;
        for (int k = 0; k < M; k++) {
            vector<Pixel> rowtmp;
            for (int j = 0; j < N; ++j) {
                bool ptmp;
                cin >> ptmp;
                rowtmp.emplace_back(ptmp);
            }
            slicetmp.push_back(move(rowtmp));
        }
        datas.push_back(move(slicetmp));
    }
    int ans = 0;
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < N; ++k) {
                if (!datas[i][j][k].visited && datas[i][j][k].stroke) {
                    int tsum = findVolume(i, j, k);
                    if (tsum >= T)
                        ans += tsum;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
