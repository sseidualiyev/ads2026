/*
Problem I: Problem C. Azat likes sorting
Input
qwertyuioplkjvbn
Output
beijklnopqrtuvwy
*/
#include <iostream>
using namespace std;

void quick(string& a, int l, int r) {
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
    string s; cin >> s;
    quick(s, 0, s.size() - 1);
    cout << s;
}
