#include <iostream>
#include <cmath>
using namespace std;

void firstTask() {
    double x, a, b, c, y;
    cout<<"Enter the value of x:";
    cin >> x;
    do {
        cout<<"Enter the value of a, b and c:";
        cin >> a >> b;
        if(a + b - x == 0) {
            cout<<"Division by zero error" << endl;
        }
    } while (a + b - x == 0);
    cin >> c;
    if(x >= 1.5) {
        y = ((pow(x, 3) + 3 * a) * c) / (a - b + x);
        cout << "x >= 1.5" << endl;
    }
    else {
        y = pow(sin(a), 2) * pow(sin(b), 2);
        cout << "x < 1.5" << endl;
    }
    cout << "Result: " << y << endl;
}
void secondTask() {
    double x, y;
    cout<<"Enter the value of x and y:";
    cin >> x >> y;
    cout << "Is point in the area: ";
    if(x >= 0 and y >= 0) {
        double y_of_function = -x + 2;
        if(y_of_function >= y) {
            cout << "TRUE" << endl;
        }
        else {
            cout << "FALSE" << endl;
        }
    }
    else {
        cout << "FALSE" << endl;
    }
}
int main() {
    cout << "1. Function system;\n2. Graphics.\nChose the task:" << endl;
    int task;
    cin >> task;
    switch(task) {
        case 1:
            firstTask();
            break;
        case 2:
            secondTask();
            break;
        default:
            cout<< "Wrapping wrong task!"<< endl;
    }
    return 0;
}
