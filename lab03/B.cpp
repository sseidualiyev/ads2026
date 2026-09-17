/*
Problem B: Patchwork Staccato I
Input format
The first line contains two integers n and q.
The second line contains n integers a1 a2 an — the array itself, given in arbitrary order.
Each of the next q lines contains 4 integers — one query.

Output format
Output q lines — the answer to each query in the order they are given.
Examples
Input
7 3
21 1 2 3 5 8 13
1 5 13 21
1 1 2 3
1 3 2 8
Output
6
3
5
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Helper: Counts how many numbers in sorted vector 'a' fall between 'l' and 'r' (inclusive)
int countRange(const vector<int>& a, int l, int r) {
    if (l > r) return 0; // Invalid range
    
    // lower_bound finds the first element >= l
    auto start = lower_bound(a.begin(), a.end(), l);
    // upper_bound finds the first element > r
    auto end = upper_bound(a.begin(), a.end(), r);
    
    // The difference between iterators gives the exact count of elements
    return end - start; 
}

int main() {
    int n, q;
    if (!(cin >> n >> q)) return 0;

    // PHASE 1: Read and sort the array
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end()); // Array MUST be sorted for lower/upper_bound to work

    // PHASE 2: Process queries
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        // 1. Count elements in both individual ranges
        int total = countRange(a, l1, r1) + countRange(a, l2, r2);

        // 2. Find the overlapping range (Intersection)
        int overlapLeft = max(l1, l2);
        int overlapRight = min(r1, r2);

        // 3. Subtract the overlap to avoid double-counting
        total -= countRange(a, overlapLeft, overlapRight);
        
        cout << total << "\n";
    }

    return 0;
}
