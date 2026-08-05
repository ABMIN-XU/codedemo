#include<bits/stdc++.h>
using namespace std;
int kmp(string s,string p) {
    int n=s.length();
    int m=p.length();
    vector<int> lps(m,0);
    int len=0;
    int i=1;
    while(i<m) {
        if(p[i]==p[len]) {
            len++;
            lps[i]=len;
            i++;
        }
        else {
            if(len!=0) {
                len=lps[len-1];
            }
            else {
                lps[i]=0;
                i++;
            }
        }
    }
    i=0;
    int j=0;
    while(i<n) {
        if(s[i]==p[j]) {
            i++;
            j++;
        }
        if(j==m) {
            return i-j;
        }
        else if(i<n && s[i]!=p[j]) {
            if(j!=0) {
                j=lps[j-1];
            }
            else {
                i++;
            }
        }
    }
    return -1;
}
int main() {
    string s="ababcabcabababd";
    string p="ababd";
    int index=kmp(s,p);
    if(index!=-1) {
        cout<<"Pattern found at index "<<index<<endl;
    }
    else {
        cout<<"Pattern not found"<<endl;
    }
    return 0;
}