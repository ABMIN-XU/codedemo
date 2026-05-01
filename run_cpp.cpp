#include<iostream>
#include<vector>
using namespace std;
int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    long long u = 0;
    long long c = 0;
    long long p = n-1;
    while(p!=0){
       for(long long i = p; i >= 0; i--) {
            if(b[i]>u){
               u=b[i];
               a[i]+=c;
               p=i;
               c=0;
            }
            c+=a[i];
        }
    }
    a[0] += u;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * b[i];
    }
    cout << ans<< endl;
    return 0;
}