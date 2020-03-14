#include <bits/stdc++.h>
using namespace std;

int n;
int x;

int main() {
    scanf("%d", &n);
    while(n-- > 0) {
        scanf("%d", &x);
    }
    printf("%s", (x == 1) ? "PIERWSZY" : "DRUGI");
}