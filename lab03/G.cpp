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
    if (!(cin >> n >> k)) return 0;

    // PHASE 1: Read inputs and find the upper bound
    vector<double> ropes(n);
    double right = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
        if (ropes[i] > right) {
            right = ropes[i]; // Max possible answer is the length of the longest rope
        }
    }

    // PHASE 2: Core Logic - Floating-Point Binary Search
    double left = 0;

    // 100 iterations guarantee accuracy up to ~30 decimal places (2^-100)
    for (int i = 0; i < 100; i++) {
        double mid = left + (right - left) / 2.0;

        long long pieces = 0;
        for (double rope : ropes) {
            pieces += (long long)(rope / mid); // How many 'mid' length pieces fit in this rope?
        }

        if (pieces >= k) {
            left = mid;  // We got enough pieces, but maybe we can cut them longer
        } else {
            right = mid; // Not enough pieces, we MUST cut them shorter
        }
    }

    // PHASE 3: Print result with high precision
    // fixed and setprecision ensure it prints trailing zeros and doesn't use scientific notation
    cout << fixed << setprecision(9) << left << '\n';

    return 0;
}
