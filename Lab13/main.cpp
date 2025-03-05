#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));

    int const SIZE = 10;

    int arr[SIZE][SIZE];
    int odds = 0, evens = 0;

    cout<<"Array: "<< endl;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            *(*(arr + i) + j) = rand() % 101 - 50;
            cout << *(*(arr + i) + j) << "\t";

            if(*(*(arr + i) + j) % 2 == 0) odds++;
            else evens++;
        }
        cout << endl << endl;
    }
    cout << "Main D: ";
    for(int i = 0; i < SIZE; i++) {
        cout << *(*(arr + i) + i) << "\t";
    }
    cout << endl;
    cout << "Secondary D: ";
    for(int i = 0; i < SIZE; i++) {
        cout << *(*(arr + i) + SIZE - i - 1) << "\t";
    }
    cout << endl;
    cout << "Odds: " << odds << ";\nEvens: " << evens << endl;
    return 0;
}