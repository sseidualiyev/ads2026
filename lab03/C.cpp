/*
Problem C: Debugging
Input format
First line consists of integers N and M - number of blocks and mistakes.
The second line contains N integers ai - number of lines in the i-th block.
Each of the next M lines contains one integer bi - number of line where the i-th mistake was made. 
In other words, every mistake is guaranteed to fall inside the code, so the answer always exists.
Output format
Print M lines, the i-th line must contain the number of block in which the i-th mistake was made.
Examples
Input
2 1
3 4
5
Output
2
Input
3 3
5 7 6
5
10
15
Output
1
2
3
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

// Helper: Custom Binary Search (equivalent to std::lower_bound)
int findBucket(const vector<int>& prefixSums, int target) {
    int left = 0;
    int right = prefixSums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2; // Safe middle calculation

        if (prefixSums[mid] >= target) {
            right = mid;     // Target is in the left half (or IS mid)
        } else {
            left = mid + 1;  // Target is strictly in the right half
        }
    }
    
    // Return 1-based index (since problem asks for 1st bucket, 2nd bucket, etc.)
    return left + 1; 
}

int main() {
    int n, m;
    if (!(cin >> n) || n <= 0) return 0;

    // PHASE 1: Build the Prefix Sum Array
    vector<int> prefixSums(n);
    int currentSum = 0;
    
    for (int i = 0; i < n; i++) {
        int size;
        cin >> size;
        currentSum += size;
        prefixSums[i] = currentSum; // Store cumulative total
    }

    // PHASE 2: Process the queries
    if (cin >> m) {
        for (int i = 0; i < m; i++) {
            int query;
            cin >> query;
            cout << findBucket(prefixSums, query) << "\n";
        }
    }

    return 0;
}
