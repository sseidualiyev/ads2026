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

int countRange(const vector<int>& a, int l, int r) {
    if (l > r) return 0;

    auto start = lower_bound(a.begin(), a.end(), l);
    auto end = upper_bound(a.begin(), a.end(), r);

    return end - start; 
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int total = countRange(a, l1, r1) + countRange(a, l2, r2);

        int overlapLeft = max(l1, l2);
        int overlapRight = min(r1, r2);

        total -= countRange(a, overlapLeft, overlapRight);
        
        cout << total << "\n";
    }

    return 0;
}
