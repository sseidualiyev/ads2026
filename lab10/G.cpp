/*
Problem G: Fly Me to the Moon
Input
5 6
1 3
2 1
3 5
4 3
5 4
3 2
Output
NO
*/
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> color, path;
int cyclestart = -1, cycleend = -1;
bool dfs(int v) {
    color[v] = 1;
    for(int u : adj[v]) {
        if(color[u] == 0) {path[u] = v; if(dfs(u)) return true;}
        else if(color[u] == 1) {cyclestart = u; cycleend = v; return true;}
    }
    color[v] = 2;
    return false;
}
bool acyclic(int skipu, int skipv) {
    vector<int> in(n+1, 0);
    for(int v = 1; v <= n; v++) 
        for(int u : adj[v])
            if(!(v == skipu && u == skipv)) in[u]++;
    vector<int> q;
    for(int v = 1; v <= n; v++)
        if(in[v] == 0) q.push_back(v);
    int cnt = 0;
    for(int i = 0; i < (int)q.size(); i++) {
        int v = q[i];
        cnt++;
        for(int u : adj[v]) {
            if(v == skipu && u == skipv) continue;
            if(--in[u] == 0) q.push_back(u);
        }
    }
    return cnt == n;
}
int main() {
    cin >> n >> m;
    adj.resize(n+1);
    color.assign(n+1, 0);
    path.assign(n+1, -1);
    for(int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int v = 1; v <= n; v++)
        if(color[v] == 0 && dfs(v)) break;
    if(cyclestart == -1) {cout << "YES"; return 0;}
    int v = cycleend;
    while(v != cyclestart) {
        int u = path[v];
        if(acyclic(u, v)) {cout << "YES"; return 0;}
        v = u;
    }
    if(acyclic(cycleend, cyclestart)) cout << "YES";
    else cout << "NO";
}
