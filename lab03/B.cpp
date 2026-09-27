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

int lower(const vector<int>& a, int x) {
    int l = 0, r = a.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}
int upper(const vector<int>& a, int x) {
    int l = 0, r = a.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m] <= x) l = m + 1;
        else r = m;
    }
    return l;
}
int countRange(const vector<int>& a, int l, int r) {
    return l > r ? 0 : upper(a, r) - lower(a, l);
}
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(a.begin(), a.end());
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int ans = countRange(a, l1, r1) + countRange(a, l2, r2);
        ans -= countRange(a, max(l1, l2), min(r1, r2));
        cout << ans << '\n';
    }
}
