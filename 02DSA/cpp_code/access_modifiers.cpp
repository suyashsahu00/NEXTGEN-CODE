#include <iostream>
using namespace std;

class Employee {
    int salary = 10000; //declared private here
public:
    string name;
protected:
    int id = 101; // protected: sirf child class me dikhega
};

class Child : public Employee {
public:
    void show() { cout << "ID is: " << id; } // accessible here
};

int main() {
    Employee e1;
    cout << "Enter name: ";
    cin >> e1.name;
    cout << "Your name is: "<< e1.name << endl;

    // cout << e1.salary; //'int Employee::salary' is private within this context
    // cout << e1.id;     // Error: protected main me nahi chalta

    Child c1;
    c1.show(); // child class ke through access

    return 0;
}