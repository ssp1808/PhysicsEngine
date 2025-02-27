#include <iostream>

using namespace std;

// Old Interface (Adaptee)
class OldInter {
public:
    void OldRectangle() {
        cout << "Old interface" << endl;
    }
};

// New Interface (Target)
class NewInterface {
public:
    virtual void NewRectangle() = 0;  // Pure virtual function
    virtual ~NewInterface() {}  // Virtual destructor for safe polymorphism
};

// Object Adapter (Adapter)
class ObjectAdapter : public NewInterface {
private:
    OldInter oInterface;  // Composition: Adapter contains an instance of OldInter
public:
    void NewRectangle() override {
        oInterface.OldRectangle();  // Delegating to the old interface
    }
};

int main() {
    ObjectAdapter adapter;
    adapter.NewRectangle();  // Calls OldRectangle() via adapter

    return 0;
}
