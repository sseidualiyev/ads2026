/*
Problem J: Who has a big Family?
Input
4 3
1 2
2 3
2 4
Output
2
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> children, parent;
vector<bool> vis;
void dfs(int v, int p) {
    vis[v] = true;
    parent[v] = p;
    for(int u : adj[v]) {
        if(!vis[u]) {
            dfs(u, v);
            children[v]++;
        }
    }
}
int main() {
    int n, m; cin >> n >> m;
    adj.resize(n+1);
    children.assign(n+1, 0); parent.assign(n+1, -1);
    vis.assign(n+1, false);
    for(int i = 0, u, v; i < n; i++) {
        cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i, -1);
            ans++;
        }
    }
    for(int v = 1; v <= n; v++) 
        if(parent[v] != -1 && children[v] > children[parent[v]]) ans++;
    cout << ans;
}
