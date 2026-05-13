#include <iostream>
using namespace std;

class Solution {
  public:
    int findPosition(int n) {
        // n = 2 → binary: 10

        // n & (n-1) = 10 & 01 = 00 = 0 → only one set bit ✅
        if (n <= 0 || (n & (n - 1)) != 0)
            return -1;

        int pos = 1;                  // pos = 1

        // Iteration 1: n=10, n&1 = 0 → enter loop
        while ((n & 1) == 0) {
            n >>= 1;                  // n = 10 >> 1 = 01 = 1
            pos++;                    // pos = 2
        }
        // n=01, n&1 = 1 → exit loop

        return pos;                   // return 2 ✅
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int n1 = 2; // binary "10"
    cout << "Example 1:" << endl;
    cout << "Input: n = " << n1 << endl;
    cout << "Output: " << sol.findPosition(n1) << endl;
    // Expected output: 2

    cout << "--------------------" << endl;

    // Example 2
    int n2 = 5; // binary "101"
    cout << "Example 2:" << endl;
    cout << "Input: n = " << n2 << endl;
    cout << "Output: " << sol.findPosition(n2) << endl;
    // Expected output: -1

    return 0;
}
