/*
Problem A: Vowels and consonants
Use quick sort to sort string by vowels first and in alphabetical order.
Input
41
hqghumeaylnlfdxfircvscxggbwkfnqduxwfnfozv
Output
aeiouubccddfffffggghhkllmnnnqqrsvvwwxxxyz
*/
#include <iostream>
using namespace std;

string order = "aeioubcdfghjklmnpqrstvwxyz";
int pos(char x) { return order.find(x); }
void quick(string& s, int l, int r) {
    int i = l, j = r;
    char p = s[(l + r) / 2];
    while(i <= j) {
        while(pos(s[i]) < pos(p)) i++;
        while(pos(s[j]) > pos(p)) j--;
        if(i <= j) { swap(s[i], s[j]); i++; j--; }
    }
    if(l < j) quick(s, l, j);
    if(i < r) quick(s, i, r);
}
int main() {
    int n; string s;
    cin >> n >> s;
    quick(s, 0, n - 1);
    cout << s;
}
