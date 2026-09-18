/*
Problem I: Binary search for answer; split an array into k consecutive blocks, minimize the maximum block sum.
Input
10 3
3 4 2 1 3 4 5 2 2 3
Output
12 (split into 3 blocks and the maximum is 3+4+5 and others are 3 + 4 + 2 + 1; 2 + 2 + 3.
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper: Greedily checks if we can divide the array into 'k' or fewer subarrays 
// without any subarray exceeding the 'maxAllowedSum'
bool canDivide(const vector<long long>& a, int k, long long maxAllowedSum) {
    int subarraysCount = 1;
    long long currentSum = 0;

    for (long long x : a) {
        if (currentSum + x <= maxAllowedSum) {
            // Keep adding to the current subarray
            currentSum += x;
        } else {
            // Cap reached! Start a new subarray with the current element
            subarraysCount++;
            currentSum = x;
        }
    }

    // Did we manage to do it using 'k' or fewer subarrays?
    return subarraysCount <= k;
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    // PHASE 1: Read inputs and establish the absolute Minimum and Maximum bounds
    vector<long long> a(n);
    long long left = 0;
    long long right = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        
        // The smallest possible max-sum is the single largest element in the array
        left = max(left, a[i]); 
        
        // The largest possible max-sum is the sum of the entire array (if k = 1)
        right += a[i];          
    }

    // PHASE 2: Core Logic - Binary Search on Answer
    while (left < right) {
        long long mid = left + (right - left) / 2;

        if (canDivide(a, k, mid)) {
            // 'mid' works, but maybe we can squeeze the max sum even smaller!
            right = mid;
        } else {
            // 'mid' is too tight (forces us to make more than 'k' subarrays). 
            // We MUST allow a larger sum limit.
            left = mid + 1;
        }
    }

    // PHASE 3: Print result
    // 'left' and 'right' converge on the absolute optimal (minimized) maximum sum
    cout << left << '\n';

    return 0;
}
