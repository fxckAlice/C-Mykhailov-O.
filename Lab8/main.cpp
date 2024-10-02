#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void first_task() {
    int arr[12];
    cout << "Enter number of elements in array! " << endl;
    for (int i = 0; i < 12; i++) {
        cout << i + 1 << ": ";
        cin >> arr[i];
    }
    int maxToMinArr[12];
    for (int i = 11; i >= 0; i--) {
        if(i == 11) {
            maxToMinArr[i] = arr[i];
            continue;
        }
        for(int j = 11; j >= i; j--) {
            if(maxToMinArr[j] > arr[i]) {
                for(int k = i; k < j; k++) {
                    maxToMinArr[k] = maxToMinArr[k + 1];
                }
                maxToMinArr[j] = arr[i];
                break;
            }
            if(j == i) {
                maxToMinArr[i] = arr[i];
            }
        }
    }
    cout << endl;
    cout << "Max to min array" << endl;
    for (int i = 0; i < 12; i++) {
        cout << maxToMinArr[i] << "\t";
    }
    int minToMaxArr[12];
    for (int i = 11; i >= 0; i--) {
        minToMaxArr[i] = maxToMinArr[12 - 1 - i];
    }
    cout << endl;
    cout << "Min to max array" << endl;
    for (int i = 0; i < 12; i++) {
        cout << minToMaxArr[i] << "\t";
    }

}

void second_task() {
    srand(time(NULL));

    int arr[10];
    cout << "Main array:" << endl;
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 200 - 100;
        cout << arr[i] << "\t";
    }
    int maxInt;
    for (int i = 0; i < 10; i++) {
        if(i == 0) {
            maxInt = i;
        }
        else {
            if(arr[i] > arr[maxInt]) {
                maxInt = i;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        if (arr[i] < 0 and i < maxInt) {
            arr[i] = 0;
        }
    }
    cout << endl << endl;
    cout << "Modified array:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << "\t";
    }

}

int main() {
    cout << "1. Min to max and max to min sort;\n2. Replace with 0.\nChoose the task: " << endl;
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
