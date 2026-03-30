#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> s;
        for ( int x : nums){
            if(s.count(x)) return true;
            s.insert(x);
        }
        return false;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Example 1 Output: " << (sol.containsDuplicate(nums1) ? "true" : "false") << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 3, 4};
    cout << "Example 2 Output: " << (sol.containsDuplicate(nums2) ? "true" : "false") << endl;

    // Example 3
    vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << "Example 3 Output: " << (sol.containsDuplicate(nums3) ? "true" : "false") << endl;

    return 0;
}
