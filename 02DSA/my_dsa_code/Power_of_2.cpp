#include <iostream>
using namespace std;

// every power of 2 number has exactly 1 bit set in their binary
// Binary of 8: 1000
// Binary of 7: 0111
// 8 & 7 → 1000 & 0111 = 0000  → Power of 2
class Solution {
  public:
    bool isPowerofTwo(int n) {
        // code here
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int n1 = 8;
    cout << "Example 1:" << endl;
    cout << "Input: n = " << n1 << endl;
    cout << "Output: " << (sol.isPowerofTwo(n1) ? "true" : "false") << endl;

    cout << "--------------------" << endl;

    // Example 2
    int n2 = 98;
    cout << "Example 2:" << endl;
    cout << "Input: n = " << n2 << endl;
    cout << "Output: " << (sol.isPowerofTwo(n2) ? "true" : "false") << endl;

    cout << "--------------------" << endl;

    // Example 3
    int n3 = 1;
    cout << "Example 3:" << endl;
    cout << "Input: n = " << n3 << endl;
    cout << "Output: " << (sol.isPowerofTwo(n3) ? "true" : "false") << endl;

    return 0;
}
