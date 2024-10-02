#include <cmath>
#include <iostream>
using namespace std;

void first_task() {
    int value;
    do {
        cout << "Enter value: ";
    } while (!(cin >> value));
    int i = 0;
    while (value != 1) {
        if (value % 2 == 0) {
            value /= 2;
        }
        else {
            value = value * 3 + 1;
        }
        cout << value << endl;
        i++;
    }
    cout << "steps: " << i << endl;
}

void second_task() {
    double pi4 = 0.;
    long n;
    cout << "Number of iterations? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        pi4 += pow(-1, i) * (1.0 / (1 + i * 2));
    }
    cout.precision(20);
    cout << "Pi = " << (pi4 * 4.) << endl;
}

void third_task() {
    int size;
    do{
        do {
            cout << "Enter size: ";
        }while (!(cin >> size));
        if(size < 2) cout << "Size must be greater than 1" << endl;
        if(size > 15) cout << "Size must be less than 16" << endl;
    }while(size < 2 and size > 15);

    cout << endl;
    cout << '+';
    for(int i = 0; i < size - 1; i++)
        cout << "-";
    cout << "+" << endl;
    for(int i = 0; i < size - 1; i++) {
        cout << '|';
        for(int j = 0; j < size - 1; j++)
            cout << " ";
        cout << '|' << endl;
    }
    cout << "+";
    for(int i = 0; i < size - 1; i++)
        cout << "-";
    cout << "+" << endl;
}
int main() {
    cout << "1. Collatz's hypothesis;\n2. Some actual evaluations – finding the value of π;\n3. Drawing squares (actually: rectangles).\nChoose the task: " << endl;
    int task;
    cin >> task;
    switch (task) {
        case 1:
            first_task();
        break;
        case 2:
            second_task();
        break;
        case 3:
            third_task();
        break;
        default:
            cout << "Invalid Choose Task" << endl;

    }
    return 0;
}
