#include <iostream>
using namespace std;

void firstTask() {
    int number;
    do{
        cout << "Enter the number: ";
        cin >> number;
        if (number < 100 || number > 999) {
            cout << "Invalid Input" << endl;
        }
    }while(number < 100 or number > 999);
    int hundreds, dozens, units;
    hundreds = number / 100;
    dozens = number % 100 / 10;
    units = number % 10;
    cout << hundreds << "\t" << dozens << "\t" << units << endl;
    int sum = 0;
    if (units > 3) {
        sum += units;
    }
    if (dozens > 3) {
        sum += dozens;
    }
    if (hundreds > 3) {
        sum += hundreds;
    }
    cout << "Sum: " << sum << endl;
}
void secondTask() {
    cout << "Enter the country: ";
    char country;
    cin >> country;
    country = tolower(country);
    switch (country) {
        case 'a':
            cout << "Angola\n35 million humans\n160 cities." << endl;
            break;
        case 'b':
            cout << "Belgium\n11 million humans\n143 cities." << endl;
        break;
        case 'm':
            cout << "Mexico\n128 million humans\n400 cities." << endl;
        break;
        case 'f':
            cout << "France\n68 million humans\n500 cities." << endl;
        break;
        case 'u':
            cout << "Ukraine\n36 million humans\n461 cities." << endl;
        break;
        case 'c':
            cout << "China\n1.41 billion humans\n660 cities." << endl;
        break;
        case 'r':
            cout << "Romania\n19 million humans\n320 cities." << endl;
        break;
        default:
            cout << "Invalid Input" << endl;
    }
}
int main() {
    cout << "1. 3-digit number;\n2. Mini-DB program.\nChoose the task: " << endl;
    int task;
    cin >> task;
    switch (task) {
        case 1:
            firstTask();
            break;
        case 2:
            secondTask();
            break;
        default:
            cout << "Invalid Task Choice!" << endl;
    }
    return 0;
}
