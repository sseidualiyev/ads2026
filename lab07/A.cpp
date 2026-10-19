/*
Problem A: Simple Merge
given set of strings, readline strings and mergesort.
Input
4
aabc ddfd fbbe f baaad
fddf badcf aedbe cdb ae bbd
ada bc eaced dadab b aabc fbee
bedaf edde fcaa adbf beec
Output
f aabc ddfd fbbe baaad 
ae cdb bbd fddf badcf aedbe 
b bc ada aabc fbee eaced dadab 
edde fcaa adbf beec bedaf 
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void merge(vector<string>& a, int l, int m, int r) {
    vector<string> temp;
    int i = l, j = m + 1;
    while(i <= m && j <= r) {
        if(a[i].size() <= a[j].size()) temp.push_back(a[i++]);
        else temp.push_back(a[j++]);
    }
    while(i <= m) temp.push_back(a[i++]);
    while(j <= r) temp.push_back(a[j++]);
    for(int k = 0; k < temp.size(); k++) a[l+k] = temp[k];
}
void ms(vector<string>& a, int l, int r) {
    if(l >= r) return;
    int m = (l+r)/2;
    ms(a, l, m);
    ms(a, m + 1, r);
    merge(a, l, m, r);
}
int main() {
    int n; cin >> n;
    cin.ignore();
    while(n--) {
        string line, s;
        getline(cin, line);
        stringstream ss(line);
        vector<string> a;
        while(ss >> s) a.push_back(s);
        if(!a.empty()) ms(a, 0, a.size()-1);
        for(int i = 0; i < a.size(); i++) {
            if(i > 0) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
}
