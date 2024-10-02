#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void first_task() {
    srand(time(NULL));

    cout << "Main array : " << endl;
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100 - 50;
        cout << arr[i] << "\t";
    }
    int minInt, maxInt, maxIntVal;
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            minInt = i;
            maxInt = i;
            maxIntVal = arr[i];
        }
        else {
            if(arr[i] > arr[maxInt]) {
                maxInt = i;
                maxIntVal = arr[i];
            }
            if(arr[i] < arr[minInt]) {
                minInt = i;
            }
        }
    }
    arr[maxInt] = arr[minInt];
    arr[minInt] = maxIntVal;

    cout << endl << "Modified array : " << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << "\t";
    }

}

void second_task() {
    srand(time(NULL));

    cout << "Main array : " << endl;
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100 - 50;
        cout << arr[i] << "\t";
    }
    int aNum;
    cout << endl << "Enter a number : ";
    cin >> aNum;
    int increment = 0;
    for (int i = 0; i < 10; i++) {
        if(arr[i] > aNum) {
            increment++;
        }
    }
    cout << endl << "Increment : " << increment << endl;
}

void third_task() {
    srand(time(NULL));

    cout << "Main array : " << endl;
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100 - 50;
        cout << arr[i] << "\t";
    }

    int maxInt, secondMaxInt;
    for (int i = 0; i < 10; i++) {
        if(i == 0) {
            maxInt = arr[i];
            continue;
        }
        if(arr[i] > maxInt) {
            maxInt = arr[i];
        }
    }
    for (int i = 0; i < 10; i++) {
        if(i == 0) {
            for(int j = 0; j < 10; j++) {
                if(arr[j] < maxInt) {
                    secondMaxInt = arr[j];
                }
            }
            continue;
        }
        if(arr[i] > secondMaxInt and arr[i] < maxInt) {
            secondMaxInt = arr[i];
        }
    }
    cout << endl << "Second maxInt : " << secondMaxInt << endl;
}

void fourth_task() {
    srand(time(NULL));

    cout << "Main array : " << endl;
    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 20 - 10;
        cout << arr[i] << "\t";
    }

    int zeroPos = -1;
    for (int i = 0; i < 10; i++) {
        if(arr[i] == 0) {
            zeroPos = i;
            break;
        }
    }

    cout << endl << "Zero: ";
    if(zeroPos == -1) {
        cout << "Array doesn`t have any zeros";
    }
    else {
        cout << zeroPos + 1;
    }
}

int main() {
    cout << "1. Max to min;\n2. Greater than A;\n3. Second maxInt;\n4. Zeros in array.\nChoose the task: " << endl;
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
        default:
            cout << "Invalid Choose Task" << endl;

    }
    return 0;
}
