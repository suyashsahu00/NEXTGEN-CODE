#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector <int> count (26,0);
        for (char c:s){
            count[c - 'a']++;
        }
        for (char c:t){
            count[c - 'a']--;
        }
        for (int x:count ){
            if(x!=0) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    string s1 = "anagram", t1 = "nagaram";
    cout << "Example 1 Output: " << (sol.isAnagram(s1, t1) ? "true" : "false") << endl;

    // Example 2
    string s2 = "rat", t2 = "car";
    cout << "Example 2 Output: " << (sol.isAnagram(s2, t2) ? "true" : "false") << endl;
    
    // Note: Valid Anagram usually only has 2 examples on LeetCode.

    return 0;
}
