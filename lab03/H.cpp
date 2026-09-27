/*
Problem H: k-subarray Binary search and prefix sums
minimum subarray that contains elements' sum bigger or equal to number K
Examples
Input
3 12
3 5 7
Output
2
Input
6 19
3 6 1 4 5 2
Output
5
*/
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> p(n + 1);
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        p[i + 1] = p[i] + x;
    }
    int ans = n + 1;
    for (int s = 0; s < n; s++) {
        int l = s, r = n - 1, e = -1;
        
        while (l <= r) {
            int m = (l + r) / 2;
            
            if (p[m + 1] - p[s] >= k) {
                e = m;
                r = m - 1;
            } else l = m + 1;
        }
        if (e != -1) {
            int len = e - s + 1;
            if (len < ans) ans = len;
        }
    }
    cout << (ans == n + 1 ? 0 : ans) << '\n';
}
