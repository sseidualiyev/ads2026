/*
Problem C: Points in proximity
Quick sort an array and find elements with closest absolute difference.
Input
6
-20 -3916237 -357920 -362060 30 6246457
Output
-20 30
*/
#include <iostream>
#include <vector>
using namespace std;

void quick(vector<int>& a, int l, int r) {
    int i = l, j = r, p = a[(l + r) / 2];
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
    vector<int> a(n);
    for(int& x : a) cin >> x;
    quick(a, 0, n-1);
    long long mn = 1LL << 60;
    for(int i = 1; i < n; i++) mn = min(mn, (long long)a[i] - a[i-1]);
    for(int i = 1; i < n; i++)
        if((long long)a[i] - a[i-1] == mn) cout << a[i-1] << ' ' << a[i] << ' ';
}
