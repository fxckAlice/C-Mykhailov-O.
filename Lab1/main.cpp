#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, result;
    cin >> a >> b;
    result = pow(0.5 * sin((log(exp(a + b))) * M_PI / 8) + 1.308 * cos((log(exp(a - b))) * M_PI / 8) , 2.0/3.0);
    cout << "First expression`s result: " << result << endl;

    cin >> a >> b;
    result = cbrt(exp((1 - exp(a)) / b * cos(b / a * M_PI) + log(0.708 * b)));
    cout << "Second expression`s result: " << result << endl;
    return 0;
}
