/*
Problem D: 108995. Restore the string
Input
5
7 15 59 147 371
Output
hello
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n; cin >> n;
    vector<long long> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    string s = "";
    long long prev = 0, p = 1;
    for(int i = 0; i < n; i++) {
        long long x = (h[i] - prev) / p;
        s += char(x + 'a');
        prev = h[i];
        p *= 2;
    }
    cout << s;
}
