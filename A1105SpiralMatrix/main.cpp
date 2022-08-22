#include <bits/stdc++.h>
// Accepted!
using namespace std;
int n, m;
array<array<int, 150>, 150> M;
priority_queue<int> datas;
void FillToRight(int& left, int& right, int& top, int& bottom) {
    if (left >= right || datas.empty()) return;
    for (int i = left; i <= right; ++i) {
        M[top][i] = datas.top();
        datas.pop();
    }
    top++;
}
void FillToBottom(int& left, int& right, int& top, int& bottom) {
    if (top > bottom || datas.empty()) return;
    for (int i = top; i <= bottom; i++) {
        M[i][right] = datas.top();
        datas.pop();
    }
    right--;
}
void FillToLeft(int& left, int& right, int& top, int& bottom) {
    if (left >= right || datas.empty()) return;
    for (int i = right; i >= left; --i) {
        M[bottom][i] = datas.top();
        datas.pop();
    }
    bottom--;
}
void FillToTop(int& left, int& right, int& top, int& bottom) {
    if (top > bottom || datas.empty()) return;
    for (int i = bottom; i >= top; --i) {
        M[i][left] = datas.top();
        datas.pop();
    }
    left++;
}


int main() {
    int N;
    cin >> N;
    for (int i = sqrt(N); i >= 1; --i) {
        if (N % i == 0) {
            n = i;
            m = N / n;
            break;
        }
    }
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        datas.push(tmp);
    }
    int left = 0, right = n - 1, top = 0, bottom = m - 1;
    while (!datas.empty()) {
        FillToRight(left, right, top, bottom);
        FillToBottom(left, right, top, bottom);
        FillToLeft(left, right, top, bottom);
        FillToTop(left, right, top, bottom);
    }
    for (int i = 0; i < m; ++i) {
        bool first = true;
        for (int j = 0; j < n; ++j) {
            if (first) {
                cout << M[i][j];
                first = false;
            }
            else cout << " " << M[i][j];
        }
        cout << endl;
    }
    return 0;
}
