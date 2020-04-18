#include <bits/stdc++.h>
#define pu push_back
using namespace std;

const int N = 8e3 + 15;

int n, m;

vector <int> G[2 * N], K[2 * N];

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int a2 = a + (a % 2) ? 1 : -1;
        int b2 = b + (b % 2) ? 1 : -1;
        K[a].pu(b);
        K[b].pu(a);
        G[a].pu(b2);
        G[b].pu(a2);
    }
    return 0;
}