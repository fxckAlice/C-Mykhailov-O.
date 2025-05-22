#include <iostream>
#include <numeric>
#include <string>
using namespace std;
class Fraction{
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();
    Fraction plus(Fraction that);
    Fraction minus(Fraction that);
    Fraction times(Fraction that);
    Fraction by(Fraction that);
    bool isGreaterThan(Fraction that);
    bool isLessThan(Fraction that);
    bool isEqual(Fraction that);
private:
    int numerator;
    int denominator;
    void reduce();
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
    this->reduce();
}
string Fraction::toString() {
    string answer;
    if (abs(numerator) >= abs(denominator)) {
        answer += to_string(numerator / denominator) + " ";
        numerator = abs(numerator);
    }
    if (numerator % denominator != 0) {
        answer += to_string(numerator % denominator) + "/" + to_string(denominator);
    }
    return answer;
}
double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}
void Fraction::reduce() {
    int gc = gcd(this->numerator, this->denominator);
    this->numerator /= gc;
    this->denominator /= gc;
}
Fraction Fraction::plus(Fraction that) {
    int num = this->numerator * that.denominator + this->denominator * that.numerator;
    int den = this->denominator * that.denominator;
    Fraction result(num, den);
    result.reduce();
    return result;
}
Fraction Fraction::minus(Fraction that) {
    int num = this->numerator * that.denominator - this->denominator * that.numerator;
    int den = this->denominator * that.denominator;
    Fraction result(num, den);
    result.reduce();
    return result;
}

Fraction Fraction::times(Fraction that) {
    int num = this->numerator * that.numerator;
    int den = this->denominator * that.denominator;
    Fraction result(num, den);
    result.reduce();
    return result;
}
Fraction Fraction::by(Fraction that) {
    int num = this->numerator * that.denominator;
    int den = this->denominator * that.numerator;
    Fraction result(num, den);
    result.reduce();
    return result;
}
bool Fraction::isGreaterThan(Fraction that) {
    return this->toDouble() > that.toDouble();
}
bool Fraction::isLessThan(Fraction that) {
    return this->toDouble() < that.toDouble();
}
bool Fraction::isEqual(Fraction that) {
    return this->toDouble() == that.toDouble();
}
char sym_to_compare(Fraction f1, Fraction f2) {
    if (f1.isGreaterThan(f2)) {
        return '>';
    }
    if (f1.isLessThan(f2)) {
        return '<';
    }
    return '=';
}
int main() {
    cout << "Enter two fractions:";
    string first, second;
    cin >> first >> second;
    Fraction f1(stoi(first.substr(0, first.find('/'))), stoi(first.substr(first.find('/') + 1, first.length())));
    Fraction f2(stoi(second.substr(0, second.find('/'))), stoi(second.substr(second.find('/') + 1, second.length())));
    cout << f1.toString() << sym_to_compare(f1, f2) << f2.toString() << endl;
    return 0;
}