#include <iostream>
using namespace std;
int main()
{
    int num = 0;

    cout << "Enter a num: ";
    cin >> num;
    int count = 0;
    if (num == 0)
    {
        count = 1;
    }
    while (num != 0) // example: 1234 -> 123 -> 12 -> 1
    {
        int lastDigit = num % 10; // lastDigit = last digit (e.g. 1234 % 10 = 4)
        if (lastDigit % 2 == 0)   // check if lastDigit is even (4%2==0 true, 3%2!=0 false)
        {
            count++; // increment count of even digits
        }
        num = num / 10; // remove the last digit (1234 / 10 = 123)
    }
    cout << "Number of even count: " << count << endl;

    return 0;
}