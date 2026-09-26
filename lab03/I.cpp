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

bool canDivide(const vector<long long>& a, int k, long long maxAllowedSum) {
    int subarraysCount = 1;
    long long currentSum = 0;

    for (long long x : a) {
        if (currentSum + x <= maxAllowedSum) currentSum += x;
        else {
            subarraysCount++;
            currentSum = x;
        }
    }

    return subarraysCount <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    long long left = 0;
    long long right = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        left = max(left, a[i]); 

        right += a[i];          
    }

    while (left < right) {
        long long mid = left + (right - left) / 2;

        if (canDivide(a, k, mid)) right = mid;
        else left = mid + 1;
    }

    cout << left << '\n';
    return 0;
}
