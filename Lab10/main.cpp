#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void first_task() {
    srand(time(NULL));
    int const M = 4, N = 3;
    int arr[M][N];
    for(int i = 0; i < M; i++) {
        int evenNum = 0;
        for(int j = 0; j < N; j++) {
            arr[i][j] = rand() % 100 - 50;
            if(arr[i][j] % 2 == 0) {
                evenNum++;
            }
            cout << arr[i][j] << "\t";
        }
        cout << "\t\tEven numbers: " << evenNum << endl;
    }
}

void second_task() {
    srand(time(NULL));
    int const M = 6, N = 4;
    int arr[M][N];
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            arr[i][j] = rand() % 100 - 50;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < N; i++) {
        int evenNum = 0;
        for(int j = 0; j < M; j++) {
            if(arr[j][i] % 2 == 0) {
                evenNum++;
            }
        }
        cout << "EN:" << evenNum << "\t";
    }
}

void third_task() {
    srand(time(NULL));
    int const M = 5, N = 7;
    int arr[M][N];
    for(int i = 0; i < M; i++) {
        int rowSum = 0;
        for(int j = 0; j < N; j++) {
            arr[i][j] = rand() % 100 - 50;
            rowSum += arr[i][j];
            cout << arr[i][j] << "\t";
        }
        cout << "\t\tRow sum: " << rowSum << endl;
    }
}

void fourth_task() {
    srand(time(NULL));
    int const M = 4, N = 6;
    int arr[M][N];
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            arr[i][j] = rand() % 100 - 50;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    for(int i = 0; i < N; i++) {
        int columnSum = 0;
        for(int j = 0; j < M; j++) {
            columnSum += arr[j][i];
        }
        cout << "Sum:" << columnSum << "\t";
    }
}

void fifth_task() {
    srand(time(NULL));
    int const M = 3, N = 4;
    int arr[M][N];
    int maxInt;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            arr[i][j] = rand() % 100 - 50;
            cout << arr[i][j] << "\t";
            if(i == 0 and j == 0) {
                maxInt = arr[i][j];
            }
            else if(arr[i][j] > maxInt) {
                maxInt = arr[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "Max value: " << maxInt << endl;
}

void sixth_task() {
    srand(time(NULL));
    int const M = 4, N = 7;
    int arr[M][N];
    int minInt;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            arr[i][j] = rand() % 100 - 50;
            cout << arr[i][j] << "\t";
            if(i == 0 and j == 0) {
                minInt = arr[i][j];
            }
            else if(arr[i][j] < minInt) {
                minInt = arr[i][j];
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "Min value: " << minInt << endl;
}

void seventh_task() {
    srand(time(NULL));
    int const M = 3;
    int arr[M][M];
    int ftDiagonalsSum = 0, sdDiagonalsSum = 0;
    for(int i = 0; i < M; i++) {
        cout << "\t";
        for(int j = 0; j < M; j++) {
            arr[i][j] = rand() % 100 - 50;
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    for(int i = 0; i < M; i++) {
        ftDiagonalsSum += arr[i][i];
        sdDiagonalsSum += arr[i][M - i - 1];
    }
    cout << "Sum:" << sdDiagonalsSum << "\t\t\t\t" << "Sum:" << ftDiagonalsSum << endl;

}
int main(){
    cout << "1. Even numbers in a row;\n2. Even numbers in a column;\n3. Row sum;\n4. Column sum;\n5. Max value;\n6. Min value;\n7. Diagonals` sum.\nChoose the task: " << endl;
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
        case 6:
            sixth_task();
        break;
        case 7:
            seventh_task();
        break;
        default:
            cout << "Invalid Choose Task" << endl;

    }
    return 0;
}
