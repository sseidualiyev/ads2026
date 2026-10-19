/*
Problem E: Squares of a Sorted Array
given a sorted array, sort squares of array.
Input
5
-4 -1 0 3 10
Output
0 1 9 16 100
*/
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<long long>& a, vector<long long>& b, vector<long long>& ans) {
    int i = 0, j = 0, k = 0;
    while(i < a.size() && j < b.size()) {
        if(a[i] <= b[j]) ans[k++] = a[i++];
        else ans[k++] = b[j++];
    }
    while(i < a.size()) ans[k++] = a[i++];
    while(j < b.size()) ans[k++] = b[j++];
}
int main() {
    int n; cin >> n;
    vector<int> x(n);
    for(int& i : x) cin >> i;
    vector<long long> a, b, ans(n);
    int i = 0;
    while(i < n && x[i] < 0) {
        a.push_back(1LL * x[i] * x[i]);
        i++;
    }
    for(int j = i; j < n; j++) b.push_back(1LL * x[j] * x[j]);
    for(int l = 0, r = (int)a.size() - 1; l < r; l++, r--) swap(a[l], a[r]);
    merge(a, b, ans);
    for(long long& x : ans) cout << x << ' ';
}
