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
    if (!(cin >> n >> k)) return 0;

    // PHASE 1: Read inputs and extract the necessary dimension
    vector<long long> requiredSizes(n);
    
    for (int i = 0; i < n; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        // The size required to enclose this item is dictated by its furthest edge
        requiredSizes[i] = max(x2, y2); 
    }

    // PHASE 2: Sort the sizes in ascending order
    sort(requiredSizes.begin(), requiredSizes.end());

    // PHASE 3: Print the k-th smallest size
    // k is usually 1-based in problem descriptions, so we use k - 1 for a 0-based array
    cout << requiredSizes[k - 1] << '\n';

    return 0;
}
