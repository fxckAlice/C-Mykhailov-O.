#include <iostream>
#include <cmath>

using namespace std;

double function_first(int x) {
    return pow(sin(x), 5) + fabs(5 * x - 1.5);
}
void first_task() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        do {
            cout << "Please enter a number " << i + 1 << ": " << endl;
        }while (cin >> arr[i]);
    }
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ": " << function_first(arr[i]) << endl;
    }
}

void second_task() {
    long ans = 1;
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0) {
            ans *= i;
            cout << ans << endl;
        }
    }
}

double function_second(int x) {
    return sin(x) + sqrt(-x);
}
void third_task() {
    int a, b, h;
    do{
        do {
            cout << "Please enter the range: " << endl;
        }while (!(cin >> a >> b));
        if (a > b) {
            cout << "A is greater than b ERROR!" << endl;
        }
    }while (a > b);
    do {
        cout << "Please enter the step: " << endl;
    }while (!(cin >> h));

    cout << "-------------------" << endl;
        cout << "  :  X  : :  Y  :  " << endl;
    cout << "-------------------" << endl;

    for(int i = a; i <= b; i++) {
        if (i > 0) {
            cout << "OUT OF RANGE EXCEPTION!" << endl;
            break;
        }
        cout << "  :  " << i << "  : :  " << function_second(i) << "  :  " << endl;
    }
}

void fourth_task() {
    int m;
    do{
        do {
            cout << "Please enter m: " << endl;
        }while (!(cin >> m));
        if (m <= 10) {
            cout << "M must be greater than 10!" << endl;
        }
    }while (m <= 10);
    int k = 1;
    while (pow (4, k + 1) < m) {
        k++;
    }
    cout << "k: " << k << endl;
    cout << pow(4, k) << " < " << m << endl;
}

void fifth_task() {
    int num;
    do {
        cout << "Please enter a number: " << endl;
    }while (!(cin >> num));
    string numStr = to_string(num);
    int ans = 1;
    bool ifHasValidPart = false;
    for(int i = 0; i < numStr.length(); i++) {
        cout << i + 1 << ": " << numStr[i] << endl;
        if(numStr[i] != '7') {
            ans *= numStr[i] - '0';
            ifHasValidPart = true;
        }
    }
    cout << "Result: " << ((ans == 1 && ifHasValidPart) ? "No valid numbers!" : to_string(ans)) << endl;


}
int main()
{
    cout << "1. Five times function;\n2. :.3 && <100;\n3. Function;\n4. 4^k < m;\n5. Numbers of input doesn`t equal to 7.\nChoose the task: " << endl;
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
        case 4:
            fourth_task();
        break;
        case 5:
            fifth_task();
        break;
        default:
            cout << "Invalid Choose Task" << endl;

    }
    return 0;
}
