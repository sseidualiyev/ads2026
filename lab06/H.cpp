/*
Problem H: Balanced char
Input
3
c f g
a
Output
c
*/
#include <iostream>
#include <vector>
using namespace std;

void quick(vector<char>& a, int l, int r) {
    int i = l, j = r;
    char p = a[(l + r) / 2];
    while(i <= j) {
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if(i <= j) swap(a[i++], a[j--]);
    }
    if(l < j) quick(a, l, j);
    if(i < r) quick(a, i, r);
}
int main() {
    int n; cin >> n;
    vector<char> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    char x; cin >> x;
    quick(a, 0, n-1);
    for(int i = 0; i < n; i++) {
        if(a[i] > x) { cout << a[i]; return 0; }
    }
    cout << a[0]; 
}
