/*
Problem D: binary search + prefix sum
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countbeaten(const vector<int>& a, int target) {
    int left = 0;
    int right = a.size();

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (a[mid] <= target) left = mid + 1;
        else right = mid;
    }
    
    return left;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + a[i]; 

    int q, power;
    cin >> q;
    while (q--) {
        cin >> power;

        int count = countbeaten(a, power);
        long long sum = prefix[count];

        cout << count << " " << sum << "\n";
    }
    return 0;
}
