#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    string name;
    int age;

    string getName() {
        return name + "\n";
    }
};
void print(Person* person)
{
    cout << person->name << " is " << person->age << " years old" << endl;
}

void task_1()
{
    Person person;
    person.name = "Harry";
    person.age = 23;
    cout << "Meet " << person.getName();
    print(&person);

    Person mark;
    person.age = 20;
    person.name = "Mark";
    cout << "Meet " << person.getName();
    print(&person);

    Person nick;
    nick.name = "Nick";
    nick.age = 19;
    cout << "Meet " << nick.getName();
    print(&nick);

    Person diego;
    diego.name = "Diego";
    diego.age = 18;
    cout << "Meet " << diego.getName();
    print(&diego);
}
//---------//
class Square
{
public:
    Square(double side);
    // Your code here
    void set_side(double side) {
        if (side >= 0){
            this->side = side;
            area = side * side;
        }
    }
void print()
{
    cout << "Square: side=" << this->side << " area=" << this->area << endl;
}
private:
    double side;
    double area;
};
Square::Square(double side)
{
    this->side = side;
    this->area = side * side;
}
void task_2()
{
    Square s(4);
    s.print();
    s.set_side(2.0);
    s.print();
    s.set_side(-33.0);
    s.print();
}

//--------//
class AdHocSquare
{
public:
    AdHocSquare(double side) {
        set_side(side);
    };
    void set_side(double side) {
        if (side >= 0) {
            this->side = side;
        }
    };
    double get_area() {
        return this->side * this->side;
    };
    void print()
    {
        cout << "Square: side=" << this->side << " area=" << this->get_area() << endl;
    }
private:
    double side;
};
class LazySquare
{
public:
    LazySquare(double side) {
        set_side(side);
        this->side_changed = true;
    };
    void set_side(double side) {
        if (side >= 0) {
            this->side = side;
            this->side_changed = true;
        }
    };
    double get_area() {
        if (this->side_changed) {
            this->side_changed = false;
            this->area = this->side * this->side;
        }
        return this->area;
    };
    void print()
    {
        cout << "Square: side=" << this->side << " area=" << this->get_area() << endl;
    }
private:
    double side;
    double area;
    bool side_changed;
};
void task_3()
{
    cout << "AdHocSquare" << endl;
    AdHocSquare ad_hoc_square(4);
    ad_hoc_square.print();
    ad_hoc_square.set_side(2.0);
    ad_hoc_square.print();
    ad_hoc_square.set_side(-33.0);
    ad_hoc_square.print();

    cout << endl << endl;
    cout << "LazySquare" << endl;
    LazySquare lazy_square(4);
    lazy_square.print();
    lazy_square.set_side(2.0);
    lazy_square.print();
    lazy_square.set_side(-33.0);
    lazy_square.print();
}
int main() {
    int task;
    cout << "Enter the number of tasks: ";
    cin >> task;
    switch (task) {
        case 1:
            task_1();
            break;
        case 2:
            task_2();
            break;
        case 3:
            task_3();
            break;
        default:
            cout << "Invalid Task:" << endl;
            break;;
    }
    return 0;
}