#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 15;

int n;
int A[N], S[N];
int r[] = {0, 2, 4, 5, 7, 9, 11};
set <int> rest;
int m;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    for(int i = 0; i < 7; i++) {
        rest.insert(r[i]);
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        S[i] = A[i];
    }
    sort(S, S + n);
    m = S[0];
    for(int i = n - 1; i >= 0; i--) {
        S[i] -= m;
    }
    // for(int i = 0; i < n; i++) {

    //     cout << S[i] << " ";
    // }
    for(int i = 0; i < 12; i++) {
        bool ok = 1;
        for(int j = 0; j < n; j++) {
            int re = (S[j] + i) % 12;
            if(rest.count(re) == 0) ok = 0;
        }
        if(ok) {
            cout << "TAK\n";
            for(int k = 0; k < n; k++) {
                cout << A[k] - m + i << " ";
            }
            return 0;
        }
    }
    cout << "NIE";
}