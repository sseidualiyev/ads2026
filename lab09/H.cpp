/*
Problem H: 147775. Splitting
Input
ababababcx
Output
2
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> zz(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > r) {l = i; r = i + z[i] - 1;}
    }
    return z;
}
int main() {
    string s; cin >> s;
    vector<int> z = zz(s);
    int ans = 0;
    for(int i = 1; 2*i < s.size(); i++) 
        if(z[i] >= i) ans++;
    cout << ans;
}
