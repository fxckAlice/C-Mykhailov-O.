#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class IPAddress {
protected:
    string address;

public:
    IPAddress(const string& addr) : address(addr) {}
    IPAddress(const IPAddress& other) : address(other.address) {}
    virtual void print() const {
        cout << address;
    }

    virtual ~IPAddress() {}
};

class IPAddressChecked : public IPAddress {
private:
    bool isCorrect;

    bool validate(const string& addr) {
        istringstream ss(addr);
        string part;
        int count = 0;

        while (getline(ss, part, '.')) {
            if (part.empty() || part.length() > 3)
                return false;

            for (char c : part) {
                if (!isdigit(c)) return false;
            }

            int num = stoi(part);
            if (num < 0 || num > 255) return false;

            count++;
        }

        return count == 4;
    }

public:
    IPAddressChecked(const string& addr)
        : IPAddress(addr), isCorrect(validate(addr)) {}

    IPAddressChecked(const IPAddressChecked& other)
        : IPAddress(other), isCorrect(other.isCorrect) {}

    void print() const override {
        IPAddress::print();
        cout << " - " << (isCorrect ? "Correct" : "Not Correct");
    }
};

int main() {
    string ip1, ip2, ip3;
    cout << "Enter 3 IP addresses:\n";
    getline(cin, ip1);
    getline(cin, ip2);
    getline(cin, ip3);

    IPAddress basic(ip1);
    IPAddressChecked check1(ip2);
    IPAddressChecked check2(ip3);

    cout << "\nOutput:\n";
    basic.print(); cout << endl;
    check1.print(); cout << endl;
    check2.print(); cout << endl;

    return 0;
}
