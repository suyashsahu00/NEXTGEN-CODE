#include <iostream>
using namespace std;

// Left shift logic
// bool checkKthBit(int n, int k) {
//     return (n & (1 << k)) != 0;
// }

bool checkKthBit(int n, int k) {
    return ((n >> k) & 1) == 1;
}


int main() {
    cout << boolalpha;
    cout << checkKthBit(4, 0) << "\n";   // false
    cout << checkKthBit(4, 2) << "\n";   // true
    cout << checkKthBit(500, 3) << "\n"; // false
}
