/*
Problem B: Path
Input
5
0 1 0 0 1
1 0 1 0 0
0 1 0 0 0
0 0 0 0 0
1 0 0 0 0
3 5
Output
3
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(auto& row : a)
        for(auto& x : row) cin >> x;
    int s, e; cin >> s >> e;
    s--; e--;
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int u = 0; u < n; u++)
            if(a[v][u] == 1 && dist[u] == -1) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
    }
    cout << dist[e];
}
