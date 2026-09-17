/*
Problem D: binary search + prefix sum
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper: Custom Binary Search (equivalent to std::upper_bound)
// Finds the count of elements that are less than or equal to the target
int countBeaten(const vector<int>& a, int target) {
    int left = 0;
    int right = a.size();

    while (left < right) {
        int mid = left + (right - left) / 2; // Safe middle calculation

        if (a[mid] <= target) {
            left = mid + 1; // target is greater/equal, so safe to include mid
        } else {
            right = mid;    // target is strictly less, restrict search to left
        }
    }
    
    return left; // Left represents the exact count of elements <= target
}

int main() {
    int n;
    if (!(cin >> n) || n <= 0) return 0;

    // PHASE 1: Read and sort competitor powers
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end()); // Must be sorted for binary search!

    // PHASE 2: Build the Prefix Sum array
    // Size is n + 1 so prefix[count] neatly gives the sum of the first 'count' elements
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i]; 
    }

    // PHASE 3: Process the queries
    int q, markPower;
    if (cin >> q) {
        while (q--) {
            cin >> markPower;

            int count = countBeaten(a, markPower);
            long long sum = prefix[count]; // O(1) lookup thanks to prefix sums

            cout << count << " " << sum << "\n";
        }
    }

    return 0;
}
