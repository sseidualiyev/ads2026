/*
Problem D: Calendar
convert date in integer and quick sort and output sorted date.
Input
3
01-12-2000
01-11-2000
31-10-2000
Output
31-10-2000
01-11-2000
01-12-2000
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Date { int d, m, y, x;};
void quick(vector<Date>& a, int l, int r) {
    int i = l, j = r, p = a[(l+r)/2].x;
    while(i <= j) {
        while(a[i].x < p) i++;
        while(a[j].x > p) j--;
        if(i <= j) swap(a[i++], a[j--);
    }
    if(l < j) quick(a, l, j);
    if(i < r) quick(a, i, r);
}
int main() {
    int n; cin >> n;
    vector<Date> a(n);
    for(auto& x : a) {
        string s; cin >> s;
        x.d = stoi(s.substr(0,2));
        x.m = stoi(s.substr(3,2));
        x.y = stoi(s.substr(6,4));
        x.x = x.y * 10000 + x.m * 100 + x.d;
    }
    quick(a, 0, n-1);
    
