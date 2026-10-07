/*
Problem F: New GPA
Input
5
Issenbayev Yernur 4 A 4 D+ 2 B 3 A+ 4
Yermekbayeva Diana 3 A+ 4 B+ 3 B 1
Kadyrov Asman 2 A+ 4 A+ 4
Stepanenko Ivan 3 C+ 3 F 1 A+ 5
Bissimbayev Arystan 3 A+ 4 A+ 5 D 1
Output
Stepanenko Ivan 3.056
Issenbayev Yernur 3.308
Yermekbayeva Diana 3.688
Bissimbayev Arystan 3.700
Kadyrov Asman 4.000
*/
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Student {
    string last, first;
    double gpa;
};
double grade(string s) {
    if (s == "A+") return 4;
    if (s == "A")  return 3.75;
    if (s == "B+") return 3.5;
    if (s == "B")  return 3;
    if (s == "C+") return 2.5;
    if (s == "C")  return 2;
    if (s == "D+") return 1.5;
    if (s == "D")  return 1;
    return 0;
}
bool less(Student a, Student b) {
    if (a.gpa != b.gpa) return a.gpa < b.gpa;
    if (a.last != b.last) return a.last < b.last;
    return a.first < b.first;
}
void quick(vector<Student>& a, int l, int r) {
    int i = l, j = r;
    Student p = a[(l + r) / 2];
  
    while (i <= j) {
        while (less(a[i], p)) i++;
        while (less(p, a[j])) j--;
        if (i <= j) swap(a[i++], a[j--]);
    }
  
    if (l < j) quick(a, l, j);
    if (i < r) quick(a, i, r);
}

int main() {
    int n; cin >> n;
    vector<Student> a(n);

    for (auto& s : a) {
        int k;
        cin >> s.last >> s.first >> k;

        double sum = 0, credits = 0;

        for (int i = 0; i < k; i++) {
            string mark;
            double c;
            cin >> mark >> c;

            sum += grade(mark) * c;
            credits += c;
        }
        s.gpa = sum / credits;
    }
    quick(a, 0, n - 1);
    cout << fixed << setprecision(3);
    for (auto s : a)
        cout << s.last << ' ' << s.first << ' ' << s.gpa << '\n';
}
