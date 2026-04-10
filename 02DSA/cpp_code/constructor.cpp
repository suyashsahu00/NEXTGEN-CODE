// A constructor is a special type of member function that is called automatically when an object is created
// A constructor has the same name as that of the class.
// A constructor does not have a return type.
#include <iostream>
using namespace std;

class Myclass {
public:
  Myclass() {
    cout<<"Hello World";
  }
};

int main() {
  Myclass myobj1;
  return 0;
}