#include <iostream>
#include <string>
using namespace std;
// pointers = variable that stores a memory address of another variable sometimes it's easier to to work with an address
int main(){
    // & address-of operator
    // * dereference operator 
    string name = "Bro";
    int age = 21;
    string freePizza[5] = {"p1", "p2", "p3", "p4", "p5"}; 

    string *pName = &name;
    int *pAge = &age;
    string *pFreePizzas = freePizza;//my array is already an address so i don't need to use address suboperator "&freePizzas"

    cout <<"Adreess with variable pName: "<<pName<<endl;
    cout <<"Value with variable *pName: "<<*pName<<endl;
    cout <<"------------------------------"<<endl;
    cout <<"Adreess with variable pAge: "<<pAge<<endl;
    cout <<"Value with variable *pAge: "<<*pAge<<endl;
    cout <<"------------------------------"<<endl;
    cout << "Memory address of array: " << freePizza << endl;
    cout << "The value contained within my pointer to my free pizzas is its memory address: " << pFreePizzas << endl;
    cout << "If I was to use the dereference operator, give me the first element of that array: " << *pFreePizzas << endl;


    return 0;
}