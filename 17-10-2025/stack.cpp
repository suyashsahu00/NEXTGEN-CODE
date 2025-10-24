#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int max_size;

public:
    // Constructor
    Stack(int max_size = 5) {
        this->arr = new int[max_size];
        this->max_size = max_size;
        this->top = -1;
    }

    // Push method with overflow check
    bool push(int x) {
        // Checking for overflow
        if ((this->top + 1) == this->max_size) {
            cout << "Overflow condition\n";
            return false;
        }
        this->arr[++this->top] = x;
        return true;
    }

    // Optional: destructor to free memory
    ~Stack() {
        delete[] this->arr;
    }
};

int main() {
    Stack st(3);

    cout << st.push(1) << endl; // 1
    cout << st.push(2) << endl; // 1
    cout << st.push(3) << endl; // 1
    cout << st.push(4) << endl; // Overflow condition, returns 0

    return 0;
}
