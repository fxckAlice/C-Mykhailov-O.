#include <iostream>
using namespace std;

void task_1() {
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int length = sizeof(vector) / sizeof(vector[0]);
    int min = INT_MAX;
    for (int i = 0; i < length; i++) {
        if (*(vector + i) < min) {
            min = *(vector + i);
        }
    }
    cout << min << endl;
}
void task_2() {
    int matrix[10][10] = { };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            *(*(matrix + i) + j) = (i + 1) * (j + 1);
        }
    }
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            cout.width(4);
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    int task;
    cout << "Enter the number of task: ";
    cin >> task;

    switch (task) {
        case 1:
            task_1();
            break;
        case 2:
            task_2();
            break;
        default:
            cout << "Wrong task!";
    }
    return 0;
}
