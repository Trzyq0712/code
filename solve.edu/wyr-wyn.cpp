#include <bits/stdc++.h>
using namespace std;

long long n;
long long s;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        s += x;
    }
    if(s % n == 0) cout << "TAK";
    else cout << "NIE";
    return 0;
}
