/*
Problem C: Multiply or Subtract
Input
5 9
Output
2
10 9 
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    const int MAX = 200000;
    vector<int> dist(MAX + 1, -1), par(MAX + 1, -1);
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        if(x == m) break;
        int a[] = {x * 2, x - 1};
        for(int y : a) {
            if( y >= 0 && y <= MAX && dist[y] == -1) {
                dist[y] = dist[x] + 1;
                par[y] = x;
                q.push(y);
            }
        }
    }
    vector<int> path;
    for(int x = m; x != n; x = par[x]) path.push_back(x);
    reverse(path.begin(), path.end());
    cout << dist[m] << '\n';
    for(int x : path) cout << x << ' ';
}
