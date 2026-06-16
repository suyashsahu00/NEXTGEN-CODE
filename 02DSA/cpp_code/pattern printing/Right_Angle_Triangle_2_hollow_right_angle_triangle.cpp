#include <iostream>
using namespace std;

int main() {
    int row;
    cout << "Enter number of rows: ";
    cin >> row;
    
    for (int n = 1; n <= row; n++) {
        for (int j = 1; j <= n; j++) {
            // Print '*' for first column, last column of the row, or the last row
            if (j == 1 || j == n || n == row) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl; // Move to the next line after each row
    }
    return 0;
}