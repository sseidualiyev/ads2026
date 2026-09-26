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
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        long long val;
        cin >> val;
        prefix[i + 1] = prefix[i] + val; 
    }

    int minLength = n + 1;

    for (int start = 0; start < n; start++) {
        int low = start;
        int high = n - 1;
        int bestEnd = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long currentSum = prefix[mid + 1] - prefix[start];

            if (currentSum >= k) {
                bestEnd = mid;
                high = mid - 1;
            } else low = mid + 1;
        }

        if (bestEnd != -1) {
            int length = bestEnd - start + 1;
            minLength = min(minLength, length);
        }
    }

    if (minLength == n + 1) cout << 0 << '\n';
    else cout << minLength << '\n';
    return 0;
}
