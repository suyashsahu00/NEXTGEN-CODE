// A constructor is a special type of member function that is called automatically when an object is created
// A constructor has the same name as that of the class.
// A constructor does not have a return type.
#include <iostream>
#include <string>
using namespace std;

class Myclass {
public:
  Myclass(int x, double y, string z) ;
};
Myclass::Myclass(int x,double y,string z) {
  cout << x << endl;
  cout << y << endl;
  cout << z;
}
int main() {
  Myclass myobj1(06,19.89,"This is text of song");
  return 0;
}