/*
Problem C: Sorter
given 2d array, sort with sum of rows, or lexicographically if sums are equal.
Input
5 3
1 2 3
1 2 4
1 3 2
6 0 0
2 3 2
Output
1 2 4 
2 3 2 
1 2 3 
1 3 2 
6 0 0 
*/
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<vector<int>>& a, int l, int m, int r) {
    vector<vector<int>> temp;
    int i = l, j = m + 1;
    while(i <= m && j <= r) {
        int sum1 = 0, sum2 = 0;
        for(int& x : a[i]) sum1 += x;
        for(int& x : a[j]) sum2 += x;
        bool left = false;
        if(sum1 > sum2) left = true;
        else if(sum1 == sum2) {
            if(a[i] <= a[j]) left = true;
        }
        if(left) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while(i <= m) temp.push_back(a[i++]);
    while(j <= r) temp.push_back(a[j++]);
    for(int k = 0; k < temp.size(); k++) a[l+k] = temp[k];
}
void ms(vector<vector<int>>& a, int l, int r) {
    if(l >= r) return;
    int m = (l+r)/2;
    ms(a, l, m);
    ms(a, m+1, r);
    merge(a, l, m, r);
}
int main() {
    int n, m; cin >> n >> m; 
    vector<vector<int>> a(n, vector<int>(m));
    for(auto& row : a)
        for(int& x : row) cin >> x;
    ms(a, 0, n-1);
    for(const auto& row : a) {
        for(const int& x : row) cout << x << ' ';
        cout << '\n';
    }
}
