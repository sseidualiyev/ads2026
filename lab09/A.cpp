/*
Problem A: 111498. Substring of a Repeated String
Input
abcd
cdabcdab
Output
3
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix(const string& s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for(int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
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
        while(j > 0 && s[i] != p[j]) j = pi[j - 1];
        if(s[i] == p[j]) j++;
        if(j == p.size()) {pos.push_back(i - p.size() + 1); j = pi[j - 1];}
    }
    return pos;
}
int main() {
    string a, b; cin >> a >> b;
    int k = (b.size() + a.size() - 1) / a.size();
    string s = "";
    for(int i = 0; i < k; i++) s += a;
    if(!kmp(s, b).empty()) cout << k;
    else {
        s += a;
        if(!kmp(s, b).empty()) cout << k + 1;
        else cout << -1;
    }
}
