#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(int n) {
    bool isPrime = true;
    for (int i = 2; i <= static_cast<int>(sqrt(n)); i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

void increment(int *number) {
    ++*number;
}
void increment(int *number, int value) {
    *number += value;
}

int main() {
    int task;
    cout << "Enter the number of tasks: ";
    cin >> task;

    switch (task) {
        case 1:
            for (int i = 2; i <= 21; i++) {
                if (isPrime(i)) {
                    cout << i << " ";
                }
            }
            cout << endl;
            break;
        case 2:
            int var = 0;
            for (int i = 0; i < 10; i++) {
                if (i % 2) {
                    increment(&var);
                }
                else {
                    increment(&var, i);
                }
            }
        cout << var << endl;
    }
    return 0;
}