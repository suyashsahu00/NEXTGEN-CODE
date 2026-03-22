#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findEquilibrium(vector<int>& arr) {

        // arr = [1, 2, 0, 3]

        int totalSum = 0;

        for (int i = 0; i < arr.size(); i++){
            totalSum += arr[i];
        }
        // i=0: totalSum = 0 + 1 = 1
        // i=1: totalSum = 1 + 2 = 3
        // i=2: totalSum = 3 + 0 = 3
        // i=3: totalSum = 3 + 3 = 6
        // ✅ totalSum = 6

        int leftSum = 0;
        // leftSum = 0 (shuru mein kuch bhi left mein nahi)

        for (int i = 0; i < (int)arr.size(); i++) {

            int rightSum = totalSum - leftSum - arr[i];

            // i=0: rightSum = 6 - 0 - 1 = 5  | leftSum(0) == rightSum(5)? ❌ | leftSum = 0+1 = 1
            // i=1: rightSum = 6 - 1 - 2 = 3  | leftSum(1) == rightSum(3)? ❌ | leftSum = 1+2 = 3
            // i=2: rightSum = 6 - 3 - 0 = 3  | leftSum(3) == rightSum(3)? ✅ | return 2

            if (leftSum == rightSum)
                return i;
            // i=2 pe condition true hui → return 2

            leftSum += arr[i];
            // leftSum update BAAD mein hota hai
            // (arr[i] khud equilibrium point hai, use left mein count nahi karte)
        }

        return -1;
        // agar koi equilibrium nahi mila to -1
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> arr1 = {1, 2, 0, 3};
    cout << "Arr = [1, 2, 0, 3] -> Expected: 2 (0-based) | Got: " << sol.findEquilibrium(arr1) << "\n";

    // Test Case 2
    vector<int> arr2 = {1, 3, 5, 2, 2};
    cout << "Arr = [1, 3, 5, 2, 2] -> Expected: 2 (0-based) | Got: " << sol.findEquilibrium(arr2) << "\n";

    // Test Case 3
    vector<int> arr3 = {1};
    cout << "Arr = [1] -> Expected: 0 (0-based) | Got: " << sol.findEquilibrium(arr3) << "\n";

    return 0;
}
