#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
          DRY RUN EXAMPLE
          Let's say: s = "cat"  and  t = "act"
        */

        // 1. Check our edge case first! If lengths don't match, instantly false.
        // For "cat" and "act", both are length 3. It passes.
        if (s.length() != t.length()) return false;

        // 2. Create an array of 26 zeros, indexing a=0, b=1, c=2, ..., z=25
        // count = [0, 0, 0, ..., 0]
        vector<int> count(26, 0);

        // 3. Count frequencies for string 's' ("cat")
        for (char c : s) {
            count[c - 'a']++;
            // Step 1: c = 'c' ('c' is 2). count[2] goes from 0 -> 1.
            // Step 2: c = 'a' ('a' is 0). count[0] goes from 0 -> 1.
            // Step 3: c = 't' ('t' is 19). count[19] goes from 0 -> 1.
        }

        // At this point, count looks like: [1 (for 'a'), 0, 1 (for 'c'), 0..., 1 (for 't') ...]

        // 4. Subtract frequencies for string 't' ("act")
        for (char c : t) {
            count[c - 'a']--;
            // Step 1: c = 'a' (0). count[0] goes from 1 -> 0.
            // Step 2: c = 'c' (2). count[2] goes from 1 -> 0.
            // Step 3: c = 't' (19). count[19] goes from 1 -> 0.
        }

        // 5. Final check. If both strings were exact matches, the net result should be all zeros.
        for (int x : count) {
            // Loop checks every number in the array.
            // If any number is NOT 0, it means the letters didn't perfectly cancel out!
            if (x != 0) return false;
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
