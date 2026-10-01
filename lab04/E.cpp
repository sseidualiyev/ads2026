/*
Problem E: Width
given BST, find vertices on each level and find maximum. USE BFS and queue.
6
1 2 1
1 3 0
3 5 0
3 6 1
2 4 1
Output
3
Input
4
1 2 0
2 3 0
2 4 1
Output
2
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> l(n+1), r(n+1);

    for (int i=0; i<n-1; i++) {
        int p,c,s; cin >> p >> c >> s;
        if (s) r[p] = c;
        else l[p] = c;
    }

    queue<int> q; q.push(1);
    int ans = 0;

    while (!q.empty()) {
        int k = q.size();
        if (k > ans) ans = k;

        while (k--) {
            int v = q.front(); q.pop();
            if (l[v]) q.push(l[v]);
            if (r[v]) q.push(r[v]);
        }
    }

    cout << ans;
}
