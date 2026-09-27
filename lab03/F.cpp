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
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
using namespace std;

bool canFinish(const vector<long long>& bags, long long h, long long k) {
    long long hours = 0;
    for (long long x : bags) {
        hours += (x + k - 1) / k;
        if (hours > h) return false;
    }
    return true;
}

int main() {
    int n;
    long long h;
    cin >> n >> h;
    vector<long long> bags(n);
    long long right = 0;
    for (long long& x : bags) {
        cin >> x;
        if (x > right) right = x;
    }
    long long left = 1;
    while (left < right) {
        long long mid = (left + right) / 2;
        if (canFinish(bags, h, mid)) right = mid;
        else left = mid + 1;
    }
    cout << left << '\n';
}
