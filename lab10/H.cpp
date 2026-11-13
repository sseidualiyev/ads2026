/*
Problem H: Number of Island
Input
4 5
11110
11010
11000
00000
Output
1
*/
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<char>> a;
void dfs(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '0') return;
    a[x][y] = '0';
    dfs(x+1, y); dfs(x-1, y);
    dfs(x, y+1); dfs(x, y-1);
}
int main() {
    cin >> n >> m;
    a.resize(n, vector<char>(m));
    for(auto& row : a)
        for(auto& x : row) cin >> x;
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == '1') {ans++; dfs(i, j);}
    cout << ans;
}
