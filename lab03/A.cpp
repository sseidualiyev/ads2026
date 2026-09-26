/*
Problem A: Binary search
Input format
The first line contains one integer n — the size of the array.
The second line contains n integers a1 a2 — the elements of the array in non-decreasing order. Equal elements are allowed.
The third line contains one integer x — the number to look for.
Output format
Print Yes if x occurs in the array, and No otherwise.
*/
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, target;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> target;

    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (a[mid] == target) {
            cout << "Yes\n";
            return 0;
        }
        else if (a[mid] < target) left = mid + 1;     
        else right = mid - 1;    
    }

    cout << "No\n";
    return 0;
}
