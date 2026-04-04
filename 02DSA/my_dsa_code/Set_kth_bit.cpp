#include <iostream>
using namespace std;

class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
         return (n | (1 << k));
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int n1 = 10, k1 = 2;
    cout << "Example 1:" << endl;
    cout << "Input: n = " << n1 << ", k = " << k1 << endl;
    cout << "Output: " << sol.setKthBit(n1, k1) << endl;
    // Expected output: 14

    cout << "--------------------" << endl;

    // Example 2
    int n2 = 15, k2 = 3;
    cout << "Example 2:" << endl;
    cout << "Input: n = " << n2 << ", k = " << k2 << endl;
    cout << "Output: " << sol.setKthBit(n2, k2) << endl;
    // Expected output: 15

    return 0;
}
