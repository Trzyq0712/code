#include <bits/stdc++.h>
using namespace std;


char h[2];
int hour;

int main() {
    scanf("%s", h);
    hour += (h[0] - '0') * 10 + (h[1] - '0');
    string out;
    if(hour >= 22) out = "noc";
    else if(hour >= 18) out = "wieczor";
    else if(hour >= 14) out = "popoludnie";
    else if(hour >= 12) out = "poludnie";
    else if(hour >= 6) out = "rano";
    else out = "noc";
    cout << out;
}