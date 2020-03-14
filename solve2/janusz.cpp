#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 15;

char num[N];

string s;

int main() {
    scanf("%s", num);
    s = num;

    bool ok = true;

    if((s.back() - '0') % 2 != 0) ok = false;

    int x = 0;

    for(char i : s) {
        x += (i - '0');
    }

    if(x % 3 != 0) ok = false;

    printf("%s", ok ? "TAK" : "NIE");

    return 0;
}
