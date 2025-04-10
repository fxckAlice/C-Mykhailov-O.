#include <iostream>
#include <string>
using namespace std;
class Fraction{
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
private:
    int numerator;
    int denominator;
};
Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw invalid_argument("denominator cannot be zero");
    }
    if ((numerator < 0 and denominator < 0) or denominator < 0) {
        this->numerator = -numerator;
        this->denominator = -denominator;
    }
    else {
        this->numerator = numerator;
        this->denominator = denominator;
    }

}
string Fraction::toString() {
    string answer;
    if (numerator >= denominator) {
        answer += to_string(numerator / denominator) + " ";
    }
    if (numerator % denominator != 0) {
        answer += to_string(numerator % denominator) + "/" + to_string(denominator);
    }
    return answer;
}
double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}




int main() {
    int num, den;
    string input = "";
    getline(cin, input);

    int divider_index = input.find('/');
    num = stoi(input.substr(0, divider_index + 1));
    den = stoi(input.substr(divider_index + 1));
    if (den == 0) {
        cout << "denominator is zero" << endl;
        return 1;
    }

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
    return 0;
}