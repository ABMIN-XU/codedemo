#include<bits/stdc++.h>
using namespace std;
vector<int> buildNext(const string &p) {
    int m = p.length();
    vector<int> next(m, 0);
    int len = 0;
    int pCur = 2;
    while (pCur < m) {
        if (p[pCur - 1] == p[len]) {
            len++;
            next[pCur] = len;
            pCur++;
        } else {
            if (len != 0) {
                len = next[len - 1];
            } else {
                next[pCur] = 0;
                pCur++;
            }
        }
    }
    return next;
}

int kmp(const string &s, const string &p) {
    int n = s.length();
    int m = p.length();
    vector<int> next = buildNext(p);

    int sCur = 0;
    int pCur = 0;
    while (sCur < n) {
        if (s[sCur] == p[pCur]) {
            sCur++;
            pCur++;
        }
        if (pCur == m) {
            return sCur - pCur;
        } else if (sCur < n && s[sCur] != p[pCur]) {
            if (pCur != 0) {
                pCur = next[pCur - 1];
            }
            else {
                sCur++;
            }
        }
    }
    return -1;
}

int main() {
    string s = "ababcabcabababd";
    string p = "ababd";
    int index = kmp(s, p);
    if (index != -1) {
        cout << "Pattern found at index " << index << endl;
    } else {
        cout << "Pattern not found" << endl;
    }
    return 0;
}