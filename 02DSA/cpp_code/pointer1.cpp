#include <iostream>
using namespace std;
int main(){
    //What is pointer? ----> data type which hold the address of other data type

    int a = 3;
    int* b = &a;
    // & ----> (address of) operator
    cout<<"The address of a is: "<<&a<<endl;
    cout<<"The address of a is: "<<b<<endl;

    // * ----> (value at) Dereference operator
    cout<<"The value at address b is: "<<*b<<endl;
    return 0; 
}


