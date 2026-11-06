/*
Problem D: 109553. Modified exttt{Towns} game
Input
Kokshetau
5
Astana
Tauemel
Tainan
Almaty
Budapest
Output
1
Tauemel
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
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
int match(const string& s, const string& p) {
    vector<int> pi = prefix(p);
    int j = 0;
    for(int i = max(0, (int)s.size() - (int)p.size()); i < s.size(); i++) {
        while(j > 0 && s[i] != p[j]) j = pi[j-1];
        if(s[i] == p[j]) j++;
    }
    return j;
}
int main() {
    string s; cin >> s;
    int n; cin >> n;
    for(char& c : s) c = tolower(c);
    vector<string> a(n);
    vector<int> len(n);
    int best = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        string p = a[i];
        for(char& c : p) c = tolower(c);
        len[i] = match(s, p);
        best = max(best, len[i]);
    }
    if(best == 0) {cout << 0; return 0;}
    for(int i = 0; i < n; i++)
        if(len[i] == best) cnt++;
    cout << cnt << '\n';
    for(int i = 0; i < n; i++)
        if(len[i] == best) cout << a[i] << '\n';
}
