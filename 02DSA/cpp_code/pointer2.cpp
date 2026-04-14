#include <iostream>
using namespace std;





int main() {
    int a = 10;

    int* p;        // 1) pointer declare
    p = &a;        // 2) pointer me address store

    cout << "a ki value: " << a << endl;
    cout << "p me kya hai (address): " << p << endl;
    cout << "*p ki value: " << *p << endl;

    *p = 20;
    cout<<" a after *p =20: "<<a<<endl;

   
    return 0;
}