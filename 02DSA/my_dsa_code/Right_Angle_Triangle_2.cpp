#include <iostream>
using namespace std;

class Solution {
  public:
    void printPattern(int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                // Print '*' for first column, last column of the row, or the last row
                if (j == 1 || j == i || i == n) {
                    cout << "* ";
                } else {
                    cout << "  ";
                }
            }
            cout << endl; // Move to the next line after each row
        }
    }
};

int main() {
    int t;
    cout << "Enter number of test cases: ";
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cout << "Enter n: ";
        cin >> n;
        Solution ob;
        ob.printPattern(n);
    }
    return 0;
}
