/*
Problem A: Marios War
Input
3 3
2 1 1
1 1 0
0 1 1
Output
4
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int m, n; cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    queue<pair<int, int>> q;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 2) q.push({i, j});
        }
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int ans = 0;
    while(!q.empty()) {
        int sz = q.size();
        while(sz--) {
            auto [x, y] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && a[nx][ny] == 1) {
                    a[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
        ans++;
    }
    for(auto &row : a)
        for(int x : row)
            if(x == 1) {cout << -1; return 0;}
    cout << max(0, ans - 1);
}
