#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void findNextGreaterElement(const vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n); 
    stack<int> s;        

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        nge[i] = (s.empty()) ? -1 : s.top();
        s.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " -> " << nge[i] << endl;
    }
}

int main() {
    vector<int> arr = {4, 5, 2, 25};

    cout << "Next Greater Elements: " << endl;
    findNextGreaterElement(arr);

    return 0;
}
