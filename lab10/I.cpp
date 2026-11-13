/*
Problem I: Beta Tester
Input
6 6
4 2
4 3
2 3
1 5
6 2
6 4
Output
Possible
1 5 6 4 2 3 
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> deg(n+1, 0);
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0) q.push(i);
    vector<int> ans;
    while(!q.empty()) {
        int v = q.top(); q.pop();
        ans.push_back(v);
        for(int u : adj[v]) {
            deg[u]--;
            if(deg[u] == 0) q.push(u);
        }
    }
    if(ans.size() != n) cout << "Impossible";
    else {
        cout << "Possible\n";
        for(int x : ans) cout << x << ' ';
    }
}
