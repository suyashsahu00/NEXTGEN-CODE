#include <iostream>
using namespace std;
int main(){
    int num = 0;
    
    cout<<"Enter a num: ";
    cin>>num;
    int count = 0;
    while (num!=0)//1234 //123//12
    {
        int lastDigit = num % 10;// lastDigit<= 1234 % 10 = 4 // lastDigit<= 123 % 10 = 3 // lastDigit<= 12 % 10 = 2 // 
        if (lastDigit % 2 ==0)// 4%2==0 // 3%2==0?no//2 % 2==0//
        {
            count++;//count = 1//2
        }
        num = num /10; // num<= 1234 / 10 = 123 // num<= 123 / 10 = 12 // num<= 12 / 10 = 1
        
    }
    cout<<"Number of even count: "<<count;
    
    return 0;
}