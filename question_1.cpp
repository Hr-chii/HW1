#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s, int elem) {
    if (s.empty()) {
        s.push(elem);
    } else {
        int topElem = s.top();
        s.pop();
        insertAtBottom(s, elem);
        s.push(topElem);
    }
}

void reverseStack(stack<int>& s) {
    if (!s.empty()) {
        int topElem = s.top();
        s.pop();
        
        reverseStack(s);
        
        insertAtBottom(s, topElem);
    }
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(28);
    s.push(29);
    s.push(30);
    s.push(31);

    cout << "before (from top to bottom): ";
    printStack(s);

    reverseStack(s);
    cout << "after (from top to bottom): ";
    printStack(s);

    return 0;
}
