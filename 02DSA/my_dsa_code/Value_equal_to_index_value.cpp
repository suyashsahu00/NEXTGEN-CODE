#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> valEqualToPos(vector<int>& arr) {
        // code here
        vector<int> result;
        int size = arr.size();
        for (int i = 0 ; i < size; i++){
            if(arr[i]==i +1){ // 1-based: position is i+1
                result.push_back(arr[i]);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> arr1 = {15, 2, 45, 12, 7};
    cout << "Example 1:" << endl;
    vector<int> res1 = sol.valEqualToPos(arr1);
    cout << "Output: ";
    for(int val : res1) cout << val << " ";
    cout << endl; // Expected output: 2

    cout << "--------------------" << endl;

    // Example 2
    vector<int> arr2 = {1};
    cout << "Example 2:" << endl;
    vector<int> res2 = sol.valEqualToPos(arr2);
    cout << "Output: ";
    for(int val : res2) cout << val << " ";
    cout << endl; // Expected output: 1

    return 0;
}
