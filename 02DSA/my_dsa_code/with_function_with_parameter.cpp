#include <iostream>
using namespace std;


int getAccesories( string Accesories) {
  if (Accesories == "cloths") {
    return 40; 
  }
  else if (Accesories == "shoes") {
    return 20; 
  }
  else if (Accesories == "cosmatics") {
    return 10; 
  }
  else {
    return 5;
  }
}
int main() {
    string Accesories;
    cout << "Enter a accesories" << endl;
    cin >> Accesories;
    int discount = getAccesories(Accesories);
    cout<< "Discount is " <<discount << " %" <<endl;
    
  return 0;
}