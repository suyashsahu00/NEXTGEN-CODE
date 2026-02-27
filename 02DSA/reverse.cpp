#include <iostream>
using namespace std;
int main(){
    int prev =0;
    int num = 0;
    cin>>num;
    while(num!=0){
        int lastDigit = num % 10;
        prev = prev *10 +lastDigit;
        num = num/10;

    }
    cout << prev << endl;
    return 0;
}