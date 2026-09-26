/*
Problem J: find minimum square boundary of given coordinates
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> requiredSizes(n);
    
    for (int i = 0; i < n; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        requiredSizes[i] = max(x2, y2); 
    }

    sort(requiredSizes.begin(), requiredSizes.end());

    cout << requiredSizes[k - 1] << '\n';

    return 0;
}
