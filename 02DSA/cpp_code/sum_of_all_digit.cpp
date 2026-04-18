#include <iostream>
using namespace std;
int main (){
    int num = 0;
    int sum = 0;
    cout<<"Enter a number: ";
    cin>>num;
    while (num!=0)//12 //1
    {
        sum = sum + num % 10;// sum<= 0 + 2 = 2 | 2 + 1 = 3
        num = num / 10;// num<= 12/10 = 1 | 1/10 = 0
    }
    cout << "Sum of digits: " << sum << endl;
    
    return 0;
}