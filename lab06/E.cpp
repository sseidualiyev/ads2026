/*
Problem E: Incomplete sorting
Input
4 3
1 2 3
4 5 6
6 7 8
9 8 7
Output
9 8 8 
6 7 7 
4 5 6 
1 2 3 
*/
#include <iostream>
#include <vector>
using namespace std;

void quick(vector<int>& a, int l, int r) {
    int i = l, j = r, p = a[(l + r) / 2];
    while (i <= j) {
        while (a[i] > p) i++;
        while (a[j] < p) j--;
        if (i <= j) swap(a[i++], a[j--]);
    }
    if (l < j) quick(a, l, j);
    if (i < r) quick(a, i, r);
}
int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& row : a)
        for (int& x : row) cin >> x;

    for (int j = 0; j < m; j++) {
        vector<int> col(n);
        for (int i = 0; i < n; i++) col[i] = a[i][j];
        quick(col, 0, n - 1);
        for (int i = 0; i < n; i++) a[i][j] = col[i];
    }
    for (auto& row : a) {
        for (int x : row)
            cout << x << ' ';
        cout << '\n';
    }
}
