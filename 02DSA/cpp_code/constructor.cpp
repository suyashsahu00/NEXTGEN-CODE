// A constructor is a special type of member function that is called
// automatically when an object is created A constructor has the same name as
// that of the class. A constructor does not have a return type.
#include <iostream>
#include <string>
using namespace std;

class Car {
public:
  string brand;
  string model;
  int year;
  Car(string x, string y, int z);
};
Car::Car(string x, string y, int z) {
  brand = x;
  model = y;
  year = z;
}
int main() {
  Car Obj1("BMW", "X5", 1999);
  Car obj2("Ford", "Mustang", 1969);

  cout << Obj1.brand << " " << Obj1.model << " " << Obj1.year << endl;
  cout << obj2.brand << " " << obj2.model << " " << obj2.year << endl;
  
  return 0;
}