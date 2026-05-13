#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans = INT_MIN;
        int sum = 0;

        int right = 0;

        int n = nums.size();

        while(right < n){
            sum = sum + nums[right];
            right++;

            ans = max(ans, sum);
            if (sum < 0){
                sum = 0;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Example 1 Output: " << sol.maxSubArray(nums1) << endl;
    // Expected output: 6

    // Example 2
    vector<int> nums2 = {1};
    cout << "Example 2 Output: " << sol.maxSubArray(nums2) << endl;
    // Expected output: 1

    // Example 3
    vector<int> nums3 = {5,4,-1,7,8};
    cout << "Example 3 Output: " << sol.maxSubArray(nums3) << endl;
    // Expected output: 23

    return 0;
}
