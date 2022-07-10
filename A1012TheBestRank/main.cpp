#include <bits/stdc++.h>
using namespace std;
int N, M;
struct Score {
    ushort C, M, E;
    float A;
    Score(ushort c, ushort m, ushort e, float a):  C(c), M(m), E(e), A(a) {}
};
vector<ushort> Cs;
vector<ushort> Ms;
vector<ushort> Es;
vector<float> As;
template<typename T>
ushort FindRank(const vector<T>& S, T score) {
    ulong ret = upper_bound(S.begin(), S.end(), score) - S.begin();
    return N - ret + 1;
}
unordered_map<string, Score> students;

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        ushort Cc, Mc, Ec;
        string Num;
        cin >> Num >> Cc >> Mc >> Ec;
        Cs.emplace_back(Cc);
        Ms.emplace_back(Mc);
        Es.emplace_back(Ec);
        float ave = ((Cc+Mc+Ec)*1.0f)/3;
        As.emplace_back(ave);
        students.emplace(Num, Score(Cc, Mc, Ec, ave));
    }
    sort(Cs.begin(), Cs.end());
    sort(Ms.begin(), Ms.end());
    sort(Es.begin(), Es.end());
    sort(As.begin(), As.end());
    for (int i = 0; i < M; ++i) {
        string Num;
        cin >> Num;
        auto x = students.find(Num);
        if (x != students.end()) {
            ulong re = FindRank(Es, x->second.E);
            ulong rm = FindRank(Ms, x->second.M);
            ulong rc = FindRank(Cs, x->second.C);
            ulong ra = FindRank(As, x->second.A);
            map<ulong, char> rank;
            rank[re] = 'E';
            rank[rm] = 'M';
            rank[rc] = 'C';
            rank[ra] = 'A';
            cout << rank.begin()->first << " " << rank.begin()->second << endl;
        }
        else
            cout << "N/A" << endl;
    }
    return 0;
}
