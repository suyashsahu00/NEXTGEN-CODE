#include <iostream>
using namespace std;

class Solution {
  public:
    int findPosition(int n) {
        // code here
        int count = 0;
        int bitPosition = 0;
        for (int i = 1; n > 0; i++) {
            // Note: Use (n & 1) == 1 instead of n & 1 == 1 due to precedence.
            if ((n & 1) == 1) {
                count++;
                bitPosition = i;
            }
            n = n >> 1;
        }
        if (count == 1) return bitPosition;
        else return -1;
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
