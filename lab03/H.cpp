/*
Problem H: k-subarray Binary search and prefix sums
minimum subarray that contains elements' sum bigger or equal to number K
Examples
Input
3 12
3 5 7
Output
2
Input
6 19
3 6 1 4 5 2
Output
5
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return 0;

    // PHASE 1: Read inputs and build Prefix Sums simultaneously
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        long long val;
        cin >> val;
        prefix[i + 1] = prefix[i] + val; 
    }

    // PHASE 2: Core Logic - Binary Search for the end of the subarray
    int minLength = n + 1; // Start with an impossibly large length

    // Try every possible starting index
    for (int start = 0; start < n; start++) {
        int low = start;
        int high = n - 1;
        int bestEnd = -1;

        // Binary search for the earliest ending index where sum >= k
        while (low <= high) {
            int mid = low + (high - low) / 2; // Safe middle calculation
            
            // O(1) subarray sum query using prefix sums
            long long currentSum = prefix[mid + 1] - prefix[start];

            if (currentSum >= k) {
                bestEnd = mid;  // We found a valid end, but let's see if we can find a closer one
                high = mid - 1; // Restrict search to the left to find a shorter length
            } else {
                low = mid + 1;  // Sum is too small, we MUST stretch the subarray further right
            }
        }

        // If a valid ending point was found for this start point
        if (bestEnd != -1) {
            int length = bestEnd - start + 1;
            minLength = min(minLength, length);
        }
    }

    // PHASE 3: Print result
    if (minLength == n + 1) {
        cout << 0 << '\n'; // No subarray found
    } else {
        cout << minLength << '\n';
    }

    return 0;
}
