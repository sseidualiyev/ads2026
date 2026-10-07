/*
Problem G: Nurbol hacker
Input
2
Aslan Nurbol
Nurbol HackMachine
Output
1
Aslan HackMachine
Input
6
Sens3i Danya
S1mple Papa
M9snoyPovar AWPMaster
IAmNoob IAmPro
Papa Sanya
IAmPro IAmNoob
Output
4
IAmNoob IAmNoob
M9snoyPovar AWPMaster
S1mple Sanya
Sens3i Danya
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct user {
    string first, last;
};
bool les(user a, user b) {
    return a.first < b.first;
}
void quick(vector<user>& a, int l, int r) {
    int i = l, j = r;
    user p = a[(l + r) / 2];
    while(i <= j) {
        while(les(a[i], p)) i++;
        while(les(p, a[j])) j--;
        if(i <= j) swap(a[i++], a[j--]);
    }
    if(l < j) quick(a, l, j);
    if(i < r) quick(a, i, r);
}
int main() {
    int n; cin >> n;
    map<string, string> curr;
    map<string, string> og;
    for(int i = 0; i < n; i++) {
        string old, now; cin >> old >> now;
        if(og.count(old)) {
            string orig = og[old];
            curr[orig] = now;
            og.erase(old);
            og[now] = orig; 
        } else {
            curr[old] = now;
            og[now] = old;
        }
    }
    vector<user> ans;
    for(auto& [old, now] : curr) ans.push_back({old, now});
    quick(ans, 0, ans.size() - 1);
    cout << ans.size() << '\n';
    for(auto x : ans) cout << x.first << ' ' << x.last << '\n';
}
