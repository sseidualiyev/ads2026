/*
Problem F: Binary search for minimum answer
Robin can steal only K number per hour.
Print the minimum number K such that Robin Hood can steal all of the N golden bars within the limit of H hours.
Examples
Input
4 8
3 6 7 11
Output
4
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canFinish(const vector<long long>& bags, long long h, long long k) {
    long long hoursNeeded = 0;

    for (long long amount : bags) {
        hoursNeeded += (amount + k - 1) / k; 

        if (hoursNeeded > h) return false; 
    }
    return true;
}

int main() {
    int n;
    long long h;
    cin >> n >> h;

    vector<long long> bags(n);
    for (int i = 0; i < n; i++) cin >> bags[i];

    long long left = 1; 
    long long right = *max_element(bags.begin(), bags.end()); 

    while (left < right) {
        long long mid = left + (right - left) / 2;

        if (canFinish(bags, h, mid)) right = mid;
        else left = mid + 1; 
    }
    cout << left << '\n'; 
    return 0;
}
