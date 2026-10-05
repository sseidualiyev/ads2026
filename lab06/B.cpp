/*
Problem B: House of love
Sort two arrays, and find common elements and output.
Input
4 2
1 2 2 1
2 2
Output
2 2 
Input
3 5
4 9 5
4 3 2 1 9
Output
4 9 
Input
0 1
1
Output

*/
#include <iostream>
#include <vector>
using namespace std;

void quick(vector<int>& a, int l, int r) {
    int i = l, j = r, p = a[(l + r) / 2];
    while(i <= j) {
        while(a[i] < p) i++;
        while(a[i] > p) j--;
        if(i <= j) swap(a[i++], a[j--]);
    }
    if(l < j) quick(a, l, j);
    if(i < r) quick(a, i, r);
}
int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int& x : a) cin >> x;
    for(int& x : b) cin >> x;
    if(n) quick(a, 0, n - 1);
    if(m) quick(b, 0, m - 1);
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] < b[j]) i++;
        else if(a[i] > b[j]) j++;
        else {
            cout << a[i] << ' ';
            i++; j++;
        }
    }
}
