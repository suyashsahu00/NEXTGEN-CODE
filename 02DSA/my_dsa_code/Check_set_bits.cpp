#include <iostream>
using namespace std;

// Agar saare bits set hain, to N aisa dikhega:
// 1, 3, 7, 15, 31, 63 … (binary: 1, 11, 111, 1111, …)
// Yeh sab numbers ka pattern: N = 2^k - 1
// N & (N + 1) agar 0 ho → saare bits set
class Solution {
  public:
    int isBitSet(int N) {
        // code here
        if (N == 0) return 0;
        return ((N & (N + 1)) == 0) ? 1 : 0;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int N1 = 7;
    cout << "Example 1:" << endl;
    cout << "Input: N = " << N1 << endl;
    cout << "Output: " << sol.isBitSet(N1) << endl;
    // Expected output: 1

    cout << "--------------------" << endl;

    // Example 2
    int N2 = 8;
    cout << "Example 2:" << endl;
    cout << "Input: N = " << N2 << endl;
    cout << "Output: " << sol.isBitSet(N2) << endl;
    // Expected output: 0

    return 0;
}
