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

struct S {
    string f, l;
    double g;
};
double grade(string s) {
    if(s=="A+") return 4;
    if(s=="A") return 3.75;
    if(s=="B+") return 3.5;
    if(s=="B") return 3;
    if(s=="C+") return 2.5;
    if(s=="C") return 2;
    if(s=="D+") return 1.5;
    if(s=="D") return 1;
    return 0;
}
bool les(const S& a, const S& b) {
    if(a.g != b.g) return a.g < b.g;
    if(a.l != b.l) return a.l < b.l;
    return a.f < b.f;
}
void heapify(vector<S>& a, int n, int i) {
    int m=i, l=2*i+1, r=2*i+2;
    if(l<n && les(a[m],a[l])) m=l;
    if(r<n && les(a[m],a[r])) m=r;
    if(m!=i) {swap(a[i],a[m]); heapify(a,n,m);}
}
void heapSort(vector<S>& a) {
    int n=a.size();
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>0;i--) {swap(a[0],a[i]); heapify(a,i,0);}
}
int main() {
    int n; cin>>n;
    vector<S> a(n);
    for(auto& s:a) {
        int k; cin>> s.l >> s.f >> k;
        double sum=0, csum=0;
        while(k--) {
            string mark; double c;
            cin >> mark >>c;
            sum+=grade(mark)*c;
            csum+=c;
        }
        s.g=sum/csum;
    }
    heapSort(a);
    cout<<fixed<<setprecision(3);
    for(auto s:a) cout<<s.l<<' '<<s.f<<' '<<s.g<<'\n';
}
