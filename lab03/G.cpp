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
    for (double& x : ropes) {
        cin >> x;
        if (x > right) right = x;
    }
    double left = 0;
    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        long long pieces = 0;
        for (double x : ropes) pieces += (long long)(x / mid);
        if (pieces >= k) left = mid;
        else right = mid;
    }
    cout << fixed << setprecision(9) << left << '\n';
}
