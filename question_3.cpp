#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void fn(const vector<int>& arr, int k) {
    queue<int> q;
    int n = arr.size();

    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            q.push(i); 
        }
    }
    for (int i = k; i <= n; i++) {
        if (!q.empty()) {
            cout << arr[q.front()] << " ";
        } else {
            cout << "0 ";
        }

        if (!q.empty() && q.front() <= i - k) {
            q.pop(); 
        }
        if (i < n && arr[i] < 0) {
            q.push(i);
        }
    }

    cout << endl;
}

int main() {
    vector<int> arr = { -8, 2, 3, -6, 10 };
    int k = 2;

    cout << "First negative integer in each window of size " << k << ": ";
    fn(arr, k);

    return 0;
}
