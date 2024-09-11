#include <iostream>
using namespace std;
void firstTask() {
    int value;
    cout << "Enter a value: ";
    cin >> value;
    bool answer = (value >= 0 and value < 10) or (value * 2 < 20 and value - 2 > -2) or (
                      value - 1 > 1 and value / 2 < 10) or value == 111;
    cout << (answer ? "THAT'S TRUE :)" : "THAT'S NOT TRUE :(") << endl;
}
void secondTask() {
    float n1, n2, n3, n4, n5;
    do{
        cout << "Enter five floats: ";
    } while (!(cin >> n1 >> n2 >> n3 >> n4 >> n5));

    int beforeDot = static_cast<int>(n1);
    int afterDot = static_cast<int>(n1 * 10) % 10;
    cout << beforeDot << "." << afterDot << endl;

    beforeDot = static_cast<int>(n2);
    afterDot = static_cast<int>(n2 * 100) % 100;
    cout << beforeDot << ".";
    if (afterDot == 0) {
        cout << "00" << endl;
    }
    else if (afterDot < 10){
        cout << "0" << afterDot << endl;
    }
    else {
        cout << afterDot << endl;
    }

    beforeDot = static_cast<int>(n3);
    afterDot = static_cast<int>(n3 * 1000000) % 1000000;
    cout << beforeDot << ".";
    if (afterDot == 0) {
        cout << "000000" << endl;
    }
    else if (afterDot < 10) {
        cout << "00000" << afterDot << endl;
    }
    else if (afterDot < 100) {
        cout << "0000" << afterDot << endl;
    }
    else if (afterDot < 1000) {
        cout << "000" << afterDot << endl;
    }
    else if (afterDot < 10000) {
        cout << "00" << afterDot << endl;
    }
    else if (afterDot < 100000) {
        cout << "0" << afterDot << endl;
    }
    else {
        cout << afterDot << endl;
    }

    beforeDot = static_cast<int>(n4);
    afterDot = static_cast<int>(n4 * 100) % 100;
    cout << beforeDot << ".";
    if (afterDot == 0) {
        cout << "00" << endl;
    }
    else if (afterDot < 10){
        cout << "0" << afterDot << endl;
    }
    else {
        cout << afterDot << endl;
    }

    cout << static_cast<int>(n5) << endl;
}
void thirdTask() {
    int n1, n2;
    do {
        cout << "Enter two integers: ";
    } while (!(cin >> n1 >> n2));
    float nF1 = 1.0 / n1;
    float nF2 = 1.0 / n2;
    if (nF1 == nF2) {
        cout << "Results are equal (by 0.000001 epsilon)" << endl;
    }
    else {
        cout << "Results are not equal (by 0.000001 epsilon)" << endl;
    }

}
void forthTask() {
    int n1, n2, n3,  n4;
    do {
        cout << "Enter parts of your IP: ";
    } while (!(cin >> n1 >> n2 >> n3 >> n4) or !(n1 > 0 and n1 < 256 and n2 > 0 and n2 < 256 and n3 > 0 and n3 < 256 and n4 > 0 and n4 < 256));
    cout << n1 << "." << n2 << "." << n3 << "." << n4 << endl;
}
int main() {
    cout << "1. Many-conditions task;\n2. Float rounder;\n3. Comparator;\n4. IP constructor.\nChoose the task: " << endl;
    int task;
    cin >> task;
    switch (task) {
        case 1:
            firstTask();
            break;
        case 2:
            secondTask();
            break;
        case 3:
            thirdTask();
            break;
        case 4:
            forthTask();
            break;
        default:
            cout << "Invalid Choose Task" << endl;

    }
    return 0;
}