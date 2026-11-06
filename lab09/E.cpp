/*
Problem E: 198309. Chainsaw Man: 13th generation
Input
5
anime 666
violetevergarden 898
mononoke 24
evangelion 4
nugman 7
Output
3330
14368
192
40
36
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix(const string& s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for(int i = 1; i < n; i++) {
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]) j = pi[j-1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
int main() {
    int t; cin >> t;
    while(t--) {
        string s; int n; cin >> s >> n;
        vector<int> pi = prefix(s);
        long long ans = s.size() + (n-1) * (s.size() - pi.back());
        cout << ans << '\n';
    }
}
