/*
Problem E: KH2O - potassium hydroxide???
Input
4 4
1 1 0 1
1 1 1 1
0 1 1 0
1 1 0 1
1 2 4
2 3 4
1 2 2
3 3 4
Output
YES
NO
YES
NO
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q; cin >> n >> q;
    vector<vector<int>> a(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    while(q--) {
        int x, y, z; cin >> x >> y >> z;
        if(a[x][y] && a[x][z] && a[y][z]) cout << "YES\n";
        else cout << "NO\n";
    }
}
