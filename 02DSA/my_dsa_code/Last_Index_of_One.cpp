#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int lastIndex(string s) {
        int len = s.size();
        
        // Loop backwards to find the last occurrence of '1'
        for(int i = len - 1; i >= 0; i--){
            if(s[i] == '1') return i; // Using '1' is more readable than 49
        }
        return -1;
    }
};

int main() {
    Solution sol;
    
    // Example test cases
    cout << "Input: '00001' -> Last Index: " << sol.lastIndex("00001") << "\n";
    cout << "Input: '0' -> Last Index: " << sol.lastIndex("0") << "\n";
    
    return 0;
}
