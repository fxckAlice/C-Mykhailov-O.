#include <iostream>
using namespace std;

struct Date {
    int hours;
    int minutes;
    int periodMinutes;
    void timePass() {
        hours = (hours + ((minutes + periodMinutes) / 60)) % 24;
        minutes = (minutes + periodMinutes) % 60;
        cout << hours << ":" << minutes << endl;
    }
    void eventDuration(int sdHours, int sdMinutes) {
        if(hours > sdHours) {
            hours = sdHours + 24 - hours;
        }
        else {
            hours = sdHours - hours;
        }
        if(minutes > sdMinutes) {
            minutes = sdMinutes + 60 - minutes;
            if(hours > 0) {
                hours--;
            }
            else {
                hours = 23;
            }
        }
        else {
            minutes = sdMinutes - minutes;
        }
        cout << hours << ":" << minutes << endl;
    }
};

void first_task() {
    cout << "Enter time (HH.MM): " << endl;
    Date timePass;
    do{
        cin >> timePass.hours;
        cin >> timePass.minutes;
        if(timePass.hours > 23 || timePass.minutes > 59 || timePass.hours < 0 || timePass.minutes < 0) {
            cout << "Invalid input! (24 <= HH <= 0, 60 <= MM <= 0)" << endl;
        }
    } while(timePass.hours > 23 || timePass.minutes > 59 || timePass.hours < 0 || timePass.minutes < 0) ;
    cout << "Enter period (min): " << endl;
    cin >> timePass.periodMinutes;
    timePass.timePass();
}
void second_task() {
    cout << "Enter first time (HH.MM): " << endl;
    Date eventDuration;
    do{
        cin >> eventDuration.hours;
        cin >> eventDuration.minutes;

        if(eventDuration.hours > 23 || eventDuration.minutes > 59 || eventDuration.hours < 0 || eventDuration.minutes < 0) {
            cout << "Invalid input! (24 <= HH <= 0, 60 <= MM <= 0)" << endl;
        }
    } while(eventDuration.hours > 23 || eventDuration.minutes > 59 || eventDuration.hours < 0 || eventDuration.minutes < 0);
    cout << "Enter second time (HH.MM): " << endl;
    int h, m;
    do{
        cin >> h >> m;
        if(h > 23 || m > 59 || h < 0 || m < 0) {
            cout << "Invalid input! (24 <= HH <= 0, 60 <= MM <= 0)" << endl;
        }
    } while(h > 23 || m > 59 || h < 0 || m < 0);
    eventDuration.eventDuration(h, m);
}

int main() {
    cout << "1. Time pass;\n2. Event duration.\nChoose the task: " << endl;
    int task;
    cin >> task;
    switch (task) {
        case 1:
            first_task();
        break;
        case 2:
            second_task();
        break;
        default:
            cout << "Invalid Choose Task" << endl;

    }
    return 0;
}
