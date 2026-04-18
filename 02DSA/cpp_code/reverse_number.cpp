#include <iostream>
using namespace std;
int main(){
    int prev = 0;
    int num = 0;
    cout<<"Enter a number: ";
    cin>>num;//123
    while (num!=0)//123!=0 | 12!=0 | 1!=0
    {
        int lastDigit = num % 10;//lastdigit<=123%10=3 | 12 % 10 = 2
        prev = prev * 10 + lastDigit;//prev<= 0 *10 + 3 =3 | 3 *10 + 2 = 32 | 32 * 10 + 1 = 321
        num = num / 10; // num<= 123/10=12 | 12/10 = 1 | 1/10 = 0
    }
    cout << prev << endl;
    return 0;
}