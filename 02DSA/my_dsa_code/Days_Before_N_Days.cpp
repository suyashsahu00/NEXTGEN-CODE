#include <iostream>
using namespace std;

class Solution {
  public:
    int nthDay(int d, int n) {
        // Effective days to go back (since days repeat every 7 days)
        int x = n % 7; 
        
        // Subtract effective days from the current day
        int y = d - x; 
        
        // If the result is negative, it means we wrapped around to the previous week
        // We add 7 to get the correct positive day index
        if (y < 0) {
            y = (7 + y);
        }
        
        return y;
    }
};

int main() {
    int t;
    cout << "Enter number of test cases: ";
    if (!(cin >> t)) return 0;
    while (t--) {
        int d, n;
        cout << "Enter current day (0 for Sun ... 6 for Sat) and N: ";
        cin >> d >> n;
        Solution ob;
        cout << "Day before N days was: " << ob.nthDay(d, n) << "\n\n";
    }
    return 0;
}
