#include <iostream>
using namespace std;

class Car {
public:
  string brand;
  string model;
  int year;
  int speed(int maxSpeed);
};

int Car::speed(int maxSpeed) {
  return maxSpeed;
}

int main() {
  Car carobj1;
  carobj1.brand = "BMW";
  carobj1.model = "X5";
  carobj1.year = 1999;
  Car carobj2;
  carobj2.brand = "Ford";
  carobj2.model = "Mustang";
  carobj2.year = 1969;

  cout << carobj1.brand << " " << carobj1.model << " " << carobj1.year << endl;
  cout << carobj2.brand << " " << carobj2.model << " " << carobj2.year << endl;
  
  return 0;
}