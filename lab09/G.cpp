/*
Problem G: 147128. Another one prefix function problem
Input
bcabcab
Output
3
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
    string s; cin >> s;
    vector<int> v = prefix(s);
    cout << s.size() - v.back();
}
