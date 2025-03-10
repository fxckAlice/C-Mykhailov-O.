#include <iostream>
#include <cmath>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};
Date today() {
    time_t now = time(NULL);
    tm tm = *localtime(&now);
    return Date{
        tm.tm_year + 1900,
        tm.tm_mon + 1,
        tm.tm_mday
    };
}
bool isLeap(int year) {
    return year % 4 == 0;
}
int monthLength(int year, int month) {
    switch (month) {
        case 1:
            return 31;
        case 2:
            return year % 4 == 0 ? 29 : 28;
        case 3:
            return 31;
        case 4:
            return 30;
        case 5:
            return 31;
        case 6:
            return 30;
        case 7:
            return 31;
        case 8:
            return 31;
        case 9:
            return 30;
        case 10:
            return 31;
        case 11:
            return 30;
        case 12:
            return 31;
        default:
            return 0;
    }
}
int main() {
    int task;
    cout << "Enter the number of tasks: ";
    cin >> task;
    switch (task) {
        case 1:
            for(int yr = 1995; yr < 2017; yr++)
                cout << yr << "->" << isLeap(yr) << endl;
        case 2:
            for(int yr = 2000; yr < 2002; yr++) {
                for(int mo = 1; mo <= 12; mo++)
                    cout << monthLength(yr,mo) << " ";
                cout << endl;
            }
        case 3:
            Date t = today();
            cout << t.year << "/" << t.month << "/" << t.day << endl;
            Date birth {};
            cout << "Enter the birth date! " << endl;
            cout << "Year: ";
            cin >> birth.year;
            cout << "Month: ";
            cin >> birth.month;
            cout << "Day: ";
            cin >> birth.day;
            cout << endl;
            if (birth.year <= t.year and birth.year > 1900 and birth.month <= 12 and birth.month >= 1 and birth.day >= 1 and birth.day <= 31) {
                Date period {};
                period.year = t.year - birth.year;

                if (birth.month > t.month) {
                    if (period.year == 0) {
                        cout << "Your birth date is greater then current";
                        return 1;
                    }
                    period.year -= 1;
                    t.month += 12;
                }
                period.month = t.month - birth.month;

                if (birth.day > t.day) {
                    if (period.month == 0) {
                        cout << "Your birth date is greater then current";
                        return 1;
                    }
                    period.month -= 1;
                    t.day += monthLength(birth.year, birth.month);
                }
                period.day = t.day - birth.day;

                cout << "Your birth date is less than current on: " << endl << period.year << " years, " << period.month << " month, " << period.day << " days" << endl;
            }
            else {
                cout << "Invalid birth date!" << endl;
                return 1;
            }

    }
    return 0;
}