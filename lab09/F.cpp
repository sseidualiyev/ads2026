/*
Problem F: 147131. Simple KMP
Input
abacaba
aba
Output
2
1 5 
*/
#include <iostream>
#include <string>
#include <vector>
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
vector<int> kmp(const string& s, const string& p) {
    vector<int> pi = prefix(p);
    vector<int> pos;
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        while(j > 0 && s[i] != p[j]) j = pi[j-1];
        if(s[i] == p[j]) j++;
        if(j == p.size()) {pos.push_back(i - p.size() + 1); j = pi[j-1];}
    }
    return pos;
}
int main() {
    string s, p; cin >> s >> p;
    vector<int> v = kmp(s, p);
    cout << v.size() << '\n';
    for(int x : v) cout << x + 1 << ' ';
}
