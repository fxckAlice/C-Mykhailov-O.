#include <iostream>
using namespace std;


class Tree {
public:
    virtual ~Tree() = default;

    virtual void draw() {
        cout << "Generic Tree\n";
    }
};

class PineTree : public Tree {
public:
    void draw() override {
        cout << "   /\\\n";
        cout << "  //\\\\\n";
    }
};

class OakTree : public Tree {
public:
    void draw() override {
        cout << "  /\\\n";
        cout << " /**\\\n";
    }
};

class PalmTree : public Tree {
public:
    void draw() override {
        cout << "  /\\\n";
        cout << " /++\\\n";
    }
};

int main() {
    Tree* forest[3];

    PineTree pine;
    OakTree oak;
    PalmTree palm;

    forest[0] = &pine;
    forest[1] = &oak;
    forest[2] = &palm;

    for (int i = 0; i < 3; ++i) {
        cout << "Drawing " << i << ":" << endl;
        forest[i]->draw();
    }

    return 0;
}
