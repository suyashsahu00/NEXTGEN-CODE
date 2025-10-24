#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Create a queue of integers
    queue<int> q;
    
    // Enqueue operations (adding elements)
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    
    cout << "Queue size: " << q.size() << endl;
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;
    
    // Dequeue operations (removing elements)
    cout << "\nRemoving elements in FIFO order:" << endl;
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    
    return 0;
}
