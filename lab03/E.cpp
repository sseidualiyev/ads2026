/*
Problem E: Patchwork Staccato II
Number of elements between bounds queries
*/
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countRange(const vector<int>& a, int l, int r) {
    if (l > r) return 0;

    auto left = lower_bound(a.begin(), a.end(), l);
    auto right = upper_bound(a.begin(), a.end(), r);

    return right - left;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int answer = countRange(a, l1, r1) + countRange(a, l2, r2);

        int overlapLeft = max(l1, l2);
        int overlapRight = min(r1, r2);

        answer -= countRange(a, overlapLeft, overlapRight);

        cout << answer << '\n';
    }
    return 0;
}
