#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int sc = 0;
    bool ok = 1;
    vector <int> v; 
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
        sc += x;
    }
    for(int x : v) {
        if(2 * x > sc) ok = 0;
    }
    // cout << sc << endl;
    printf("%s", (sc % 2 != 0 or !ok) ? "TAK" : "NIE");
    return 0;
}