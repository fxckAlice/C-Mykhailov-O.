#include <iostream>
using namespace std;
const int DivideByZero = 111;

void task_1() {
    int a = 8, b = 0, c = 0;
    cin >> b;
    try {
        if (b == 0) {
            throw "Your input is not valid, you can't divide by zero.";
        }
        c = a / b;
    } catch (const char *e) {
        cout << e << endl;
    }
    cout << c << endl;
}

void task_2() {
    try {
        int a = 0, b = 0, c = 0;
        cin >> b;
        if (b == 0) {
            throw invalid_argument("Your input is not valid, you can't divide by zero.");
        }
        cin >> a;
        c = a / b;
        cout << c << endl;
    }
    catch (invalid_argument e) {
        cout << e.what() << endl;
    }
}

float internaldiv(float arg1, float arg2)
{
    if (0==arg2)
        throw DivideByZero;
    return arg1 / arg2;
}
bool div(float &res, float arg1, float arg2) {
    res = internaldiv(arg1, arg2);
    return true;
}void task_3() {
    float r, a, b;
    while(cin >> a) {
        cin >> b;
        try{
            cout << internaldiv(a, b) << endl;
        }catch(int e) {
            cout << "Are you kidding me?" << endl;
            if (e == DivideByZero) {
                cout << "Your input is not valid. You can't divide by zero." << endl;
            }
        }
    }
}
int main() {
    int task;
    cout << "Enter task number: ";
    cin >> task;
    switch (task) {
        case 1:
            task_1();
            break;
        case 2:
            task_2();
            break;
        case 3:
            task_3();
            break;
    }
    return 0;
}