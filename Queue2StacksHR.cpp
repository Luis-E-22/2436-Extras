#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
     int q; // number of queries
    cin >> q;

    stack<int> stack1; // to handle enqueue operations
    stack<int> stack2; // to handle dequeue operations

    while (q--) {
        int query_type;
        cin >> query_type;

        if (query_type == 1) {
            // Enqueue: Add element to the queue
            int x;
            cin >> x;
            stack1.push(x);
        } 
        else if (query_type == 2) {
            // Dequeue: Remove the front element
            if (stack2.empty()) {
                // Transfer elements from stack1 to stack2 if stack2 is empty
                while (!stack1.empty()) {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            // Pop from stack2
            if (!stack2.empty()) {
                stack2.pop();
            }
        } 
        else if (query_type == 3) {
            // Print the front element
            if (stack2.empty()) {
                // Transfer elements from stack1 to stack2 if stack2 is empty
                while (!stack1.empty()) {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            // Print the front element
            if (!stack2.empty()) {
                cout << stack2.top() << endl;
            }
        }
    }

    return 0;
}

