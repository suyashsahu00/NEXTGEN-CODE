#include <iostream>
using namespace std;

class Solution {
  public:
    bool isBinaryPalindrome(int n) {
        // code here
        int rev = 0;
        int temp = n;
        
        while (temp > 0){
            rev = (rev << 1) | (temp & 1); // shift rev left, append LSB of temp
            temp >>= 1;
        }
        return n == rev;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int n1 = 17; // Binary: 10001
    cout << "Example 1:" << endl;
    cout << "Input: n = " << n1 << endl;
    cout << "Output: " << (sol.isBinaryPalindrome(n1) ? "1" : "0") << endl;
    // Expected output: 1

    cout << "--------------------" << endl;

    // Example 2
    int n2 = 16; // Binary: 10000
    cout << "Example 2:" << endl;
    cout << "Input: n = " << n2 << endl;
    cout << "Output: " << (sol.isBinaryPalindrome(n2) ? "1" : "0") << endl;
    // Expected output: 0

    return 0;
}
