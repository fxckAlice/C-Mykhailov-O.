#include <iostream>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(2, -2);
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    double *arr = new double[size];
    for (int i = 0; i < size; i++) {
        arr[i] = dist(gen);
        cout << arr[i] << endl;
    }

    delete arr;
    return 0;
}