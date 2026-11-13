/*
Problem D: Try Again
Input
5 4 7
1 2
2 3
3 4
4 5
2 1
1 1
2 1
2 2
2 5
1 3
2 5
Output
-1
0
1
4
2
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dist(n+1, -1);
    while(q--) {
        int t, v; cin >> t >> v;
        if(t == 1 && dist[v] != 0) {
            dist[v] = 0;
            queue<int> qu;
            qu.push(v);
            while(!qu.empty()) {
                int x = qu.front(); qu.pop();
                for(int u : adj[x]) {
                    if(dist[u] == -1 || dist[u] > dist[x] + 1) {
                        dist[u] = dist[x] + 1;
                        qu.push(u);
                    }
                }
            }
        }
        if(t == 2) cout << dist[v] << '\n';
    }
}
