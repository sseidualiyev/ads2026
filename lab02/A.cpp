/* 
Problem A: One-time guests
Jojo is watching a stream of lowercase Latin letters arrive one by one.
After every single letter that arrives, he wants to know the first letter of the stream so far that has occurred exactly once — “first” meaning the leftmost one among all letters that are still unique.
If at that moment every letter seen so far has occurred more than once, the answer is -1.

Input format
The first line contains one integer T — the number of test cases.
Each test case is given on two lines. The first of them contains one integer N — the length of the stream.
The second contains N lowercase Latin letters separated by single spaces — the letters in the order they arrive.

Output format
For each test case print one line with N answers separated by single spaces: the i-th of them is the first non-repeating letter of the stream after the first i letters have arrived,
or -1 if at that moment there is no such letter.

Input
2
4
a a b c
3
a a c
Output
a -1 b b 
a -1 c 
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(26);
    string history;
    int p = 0;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        cnt[c - 'a']++;

        if (cnt[c - 'a'] == 1)
            history += c;

        while (p < history.size() && cnt[history[p] - 'a'] > 1)
            p++;

        if (p < history.size()) cout << history[p] << ' ';
        else cout << "-1" << ' ';
    }

    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
}
