#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j}; //target found
                }
            }
        }
        return {} ; //target not found
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> res1 = sol.twoSum(nums1, target1);
    if (!res1.empty()) cout << "Example 1 Output: [" << res1[0] << ", " << res1[1] << "]" << endl;

    // Example 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> res2 = sol.twoSum(nums2, target2);
    if (!res2.empty()) cout << "Example 2 Output: [" << res2[0] << ", " << res2[1] << "]" << endl;

    // Example 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> res3 = sol.twoSum(nums3, target3);
    if (!res3.empty()) cout << "Example 3 Output: [" << res3[0] << ", " << res3[1] << "]" << endl;

    return 0;
}
