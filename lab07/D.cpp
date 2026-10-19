/*
Problem D: Count the Inversions
given array, merge sort and count inversions when a[i] < a[j] but i > j.
Input
5
3 1 4 1 5
Output
3
*/
#include <iostream>
#include <vector>
using namespace std;

long long merge(vector<int>& a, int l, int m, int r) {
    vector<int> temp;
    int i = l, j = m + 1;
    long long inv = 0;
    while(i <= m && j <= r) {
        if(a[i] <= a[j]) temp.push_back(a[i++]);
        else {temp.push_back(a[j++]); inv += m - i + 1;} 
    }
    while(i <= m) temp.push_back(a[i++]);
    while(j <= r) temp.push_back(a[j++]);
    for(int k = 0; k < temp.size(); k++) a[l+k] = temp[k];
    return inv;
}
long long ms(vector<int>& a, int l, int r) {
    if(l >= r) return 0;
    int m = (l+r)/2;
    long long inv = 0;
    inv += ms(a, l, m);
    inv += ms(a, m+1, r);
    inv += merge(a, l, m, r);
    return inv;
}
int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int& x : a) cin >> x;
    cout << ms(a, 0, n-1) << '\n';
}
