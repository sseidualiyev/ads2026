/*
Problem G: Binary search on answer; floating point
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<double> ropes(n);
    double right = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
        if (ropes[i] > right) right = ropes[i];
    }

    double left = 0;

    for (int i = 0; i < 100; i++) {
        double mid = left + (right - left) / 2.0;

        long long pieces = 0;
        for (double rope : ropes) pieces += (long long)(rope / mid);

        if (pieces >= k) left = mid;
        else right = mid;
    }

    cout << fixed << setprecision(9) << left << '\n';
    return 0;
}
