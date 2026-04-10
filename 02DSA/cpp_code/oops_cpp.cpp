#include <iostream>
using namespace std;

class Myclass {
public:
  int num;
  string text;
};

int main() {
  Myclass myobj;
  myobj.num = 10;
  myobj.text = "Hello World1!";
  cout << myobj.num << endl;
  cout << myobj.text <<endl;
  return 0;
}
// class Myclass {
// public:
//   int num;
//   string text;
// };

// int main() {
//   Myclass myobj;
//   myobj.num = 10;
//   myobj.text = "Hello World1!";
//   cout << myobj.num << endl;
//   cout << myobj.text <<endl;
//   return 0;
// }