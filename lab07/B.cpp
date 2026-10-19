/*
Problem B: Merge Two Sorted Arrays
given two sorted arrays, merge and sort them in one array
Input
5
4 5 6 7 10
5
2 4 6 7 8
Output
2 4 4 5 6 6 7 7 8 10
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int& x : a) cin >> x;
    int m; cin >> m;
    vector<int> b(m);
    for(int& x : b) cin >> x;
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(a[i] <= b[j]) cout << a[i++] << ' ';
        else cout << b[j++] << ' ';
    }
    while(i < n) cout << a[i++] << ' ';
    while(j < m) cout << b[j++] << ' ';
}
