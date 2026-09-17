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
    if (!(cin >> n) || n <= 0) return 0;

    // PHASE 1: Read the sorted array and the target value
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> target;

    // PHASE 2: Core Logic - Binary Search
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        // 1. Find the middle index (safely)
        int mid = left + (right - left) / 2; 

        // 2. Check the middle element
        if (a[mid] == target) {
            cout << "Yes\n";
            return 0;           // Found it, exit immediately
        } 
        // 3. If target is larger, ignore the left half
        else if (a[mid] < target) {
            left = mid + 1;     
        } 
        // 4. If target is smaller, ignore the right half
        else {
            right = mid - 1;    
        }
    }

    // PHASE 3: If the loop finishes without returning, the target isn't there
    cout << "No\n";
    return 0;
}
