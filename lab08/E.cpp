/*
Problem E: Distinct substrings
Input
abcde
Output
15
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

const long long m1 = 1000000007, m2 = 1000000009, p = 31;
struct hsh {
    vector<long long> h1, h2, p1, p2;
    hsh(string s) {
        int n = s.size();
        h1.assign(n+1, 0); h2.assign(n+1, 0);
        p1.assign(n+1, 1); p2.assign(n+1, 1);
        for(int i = 0; i < n; i++) {
            int x = s[i] - 'a' + 1;
            h1[i+1] = (h1[i]*p + x) % m1; h2[i+1] = (h2[i]*p + x) % m2;
            p1[i+1] = p1[i]*p % m1; p2[i+1] = p2[i]*p % m2;
        }
    }
    long long get1(int l, int len) {return (h1[l + len] - h1[l] * p1[len] % m1 + m1) % m1;}
    long long get2(int l, int len) {return (h2[l + len] - h2[l] * p2[len] % m2 + m2) % m2;}
};
int main() {
    string s; cin >> s;
    int n = s.size();
    hsh S(s);
    long long ans = 0;
    for(int len = 1; len <= n; len++) {
        unordered_set<unsigned long long> seen;
        for(int i = 0; i + len <= n; i++) {
            long long a = S.get1(i, len), b = S.get2(i, len);
            unsigned long long key = (static_cast<unsigned long long>(a) << 32) | b;
            seen.insert(key);
        }
        ans += seen.size();
    }
    cout << ans;
}
