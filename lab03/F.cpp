/*
Problem F: Binary search for minimum answer
Robin can steal only K number per hour.
Print the minimum number K such that Robin Hood can steal all of the N golden bars within the limit of H hours.
Examples
Input
4 8
3 6 7 11
Output
4
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper: Checks if it is possible to finish all bags at a speed of 'k' per hour
bool canFinish(const vector<long long>& bags, long long h, long long k) {
    long long hoursNeeded = 0;

    for (long long amount : bags) {
        // Integer ceiling division trick: ceil(amount / k)
        hoursNeeded += (amount + k - 1) / k; 

        if (hoursNeeded > h) {
            return false; // Too slow, exit early
        }
    }
    return true;
}

int main() {
    int n;
    long long h;
    if (!(cin >> n >> h)) return 0;

    // PHASE 1: Read inputs
    vector<long long> bags(n);
    for (int i = 0; i < n; i++) {
        cin >> bags[i];
    }

    // PHASE 2: Core Logic - Binary Search on the Answer
    long long left = 1; 
    long long right = *max_element(bags.begin(), bags.end()); // Max speed needed is eating the biggest bag in 1 hour

    while (left < right) {
        long long mid = left + (right - left) / 2;

        if (canFinish(bags, h, mid)) {
            right = mid;    // 'mid' works, but let's see if we can do it slower
        } else {
            left = mid + 1; // 'mid' is too slow, we MUST go faster
        }
    }

    // PHASE 3: Print result
    cout << left << '\n'; // 'left' and 'right' converge on the absolute minimum valid speed

    return 0;
}
