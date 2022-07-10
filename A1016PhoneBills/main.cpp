#include <bits/stdc++.h>
// not ac!
using namespace std;
uint DAILYPRICE[24];
uint daily_sum;
int N;
struct Date {
    int month, day, hour, minute;


    static double CalcPrice(const Date& start, const Date& end, uint& out_min) {
//        if (end < start) throw runtime_error("end must greater than start");
        double cost = 0.0;
        out_min = 0;
        if (start.day == end.day)
        {
            if (start.hour == end.hour) {
                uint mindiff = end.minute - start.minute;
                out_min += mindiff;
                cost += DAILYPRICE[start.hour - 1] * mindiff;
            }
            else {
                for (int i = start.hour; i <= end.hour; ++i) {
                    if (i == start.hour) {
                        out_min += 60 - start.minute;
                        cost += DAILYPRICE[i] * (60 - start.minute);
                    }
                    else if (i == end.hour) {
                        out_min += end.minute;
                        cost += DAILYPRICE[i]  * end.minute;
                    }
                    else {
                        cost += DAILYPRICE[i] * 60;
                        out_min += 60;
                    }
                }
            } // 1438
        }
        else {
            cost += DAILYPRICE[start.hour] * (60 - start.minute);
            out_min += 60 - start.minute;
            cost += DAILYPRICE[end.hour] * end.minute;
            out_min += end.minute;
            for (int i = start.hour + 1; i < 24; ++i) {
                cost += DAILYPRICE[i] * 60;
                out_min += 60;
            }
            for (int i = end.hour - 1; i >= 0; --i) {
                cost += DAILYPRICE[i] * 60;
                out_min += 60;
            }
            cost += (end.day - start.day - 1) * daily_sum * 60;
            out_min += 60 * (end.day - start.day - 1) * 24;
        }
        return cost;
    }
    bool operator<(const Date& other) const {
        if (month < other.month) return true;
        if (month == other.month)
        {
            if (day < other.day)
                return true;
            if (day == other.day)
            {
                if (hour < other.hour)
                    return true;
                if (hour == other.hour)
                    return minute < other.minute;
            }
        }
        return false;
    }
};
using OnLines = multiset<Date>;
using OffLines = multiset<Date>;
using CustData = pair<OnLines, OffLines>;
map<string, CustData> Customers;

int main() {
    for (unsigned int & i : DAILYPRICE) {
        cin >> i;
    }
    for (auto x: DAILYPRICE) {
        daily_sum += x;
    }
    cin >> N;
    char name_[25];
    int month_, day_, hour_, minute_;
    char flag[20];
    for (int i = 0; i < N; ++i) {
        scanf("%s %d:%d:%d:%d %s", name_, &month_, &day_, &hour_, &minute_, flag);
        string name(name_);
        Date cdate{};
        cdate.month = month_;
        cdate.day = day_;
        cdate.hour = hour_;
        cdate.minute = minute_;
        if (flag[1] == 'n')  // on
            Customers[name].first.insert(cdate);
        else //off
            Customers[name].second.insert(cdate);
    }
    char buf[50];
    int MONTH = Customers.begin()->second.first.begin()->month;
    ulong endflag = 0;
    for (auto c = Customers.cbegin(); c != Customers.cend(); c++) {
        auto& customer = *c;
        sprintf(buf, "%s %02d\n", customer.first.c_str(), MONTH);
        cout << buf;
        double price_sum = 0.0;
        const auto& offLines = customer.second.second;
        const auto& onLines = customer.second.first;
        for (const auto& date: offLines) {
            auto p = [&date, &onLines]() {
                auto j = onLines.crbegin();
                for (; j != onLines.crend(); ++j) {
                    if (*j < date)
                        return j;
                }
                return onLines.rend();
            }();
            uint minute = 0;
            auto cost = Date::CalcPrice(*p, date, minute) / 100;
            sprintf(buf, "%02d:%02d:%02d %02d:%02d:%02d %u $%.2lf",
                    p->day, p->hour, p->minute,date.day, date.hour, date.minute,  minute, cost);
            cout << buf << endl;
            price_sum += cost;
        }
        sprintf(buf, "Total amount: $%.2lf", price_sum);
        cout << buf;
        if (endflag < Customers.size() - 1)
            cout << endl;
        endflag++;
    }
    return 0;
}
