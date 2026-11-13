/*
Problem F: John's graph
Input
3 3
1 2
2 3
3 1
1 3
Output
YES
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
void dfs(int v) {
    vis[v] = true;
    for(int u : adj[v])
        if(!vis[u]) dfs(u);
}
int main() {
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    vis.resize(n+1, false);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y); adj[y].push_back(x);
    }
    int s, f; cin >> s >> f;
    dfs(s);
    cout << (vis[f] ? "YES" : "NO");
}
