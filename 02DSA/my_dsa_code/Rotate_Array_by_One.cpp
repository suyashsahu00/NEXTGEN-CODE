#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void rotate(vector<int>& arr) {
        int n = arr.size();

        // Edge Case: Agar array empty hai ya sirf 1 element hai, no need to rotate.
        if (n <= 1) return;

        int temp = arr[n - 1];       // Step 1: last element save karo

        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];     // Step 2: har element ko ek right shift karo
        }

        arr[0] = temp;               // Step 3: last element front pe rakho
    }
};
// n = 5
// temp = arr[4] = 5          // last element save kiya

// // Shifting loop (right se left jaao):
// i=4: arr[4] = arr[3] → arr = [1, 2, 3, 4, 4]
// i=3: arr[3] = arr[2] → arr = [1, 2, 3, 3, 4]
// i=2: arr[2] = arr[1] → arr = [1, 2, 2, 3, 4]
// i=1: arr[1] = arr[0] → arr = [1, 1, 2, 3, 4]

// Final: [5, 1, 2, 3, 4] ✅

int main() {
    Solution sol;

    // Helper function to print vector
    auto printVector = [](const vector<int>& v) {
        cout << "[";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << (i < v.size() - 1 ? ", " : "");
        }
        cout << "]\n";
    };

    // Test Case 1: Standard case
    vector<int> arr1 = {1, 2, 3, 4, 5};
    cout << "Original: "; printVector(arr1);
    sol.rotate(arr1);
    cout << "Rotated:  "; printVector(arr1);

    // Test Case 2: One element only
    vector<int> arr2 = {99};
    cout << "\nOriginal: "; printVector(arr2);
    sol.rotate(arr2);
    cout << "Rotated:  "; printVector(arr2);

    // Test Case 3: Empty array edge case
    vector<int> arr3 = {};
    cout << "\nOriginal: "; printVector(arr3);
    sol.rotate(arr3);
    cout << "Rotated:  "; printVector(arr3);

    return 0;
}
