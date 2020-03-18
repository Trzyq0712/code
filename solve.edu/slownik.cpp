#include <bits/stdc++.h>
using namespace std;

char a, b;

int main() {
    scanf("%c %c", &a, &b);

    if(tolower(a) == tolower(b)) {
        printf("%c", (a > b ? a : b));
    }
    else {
        printf("%c", (tolower(a) < tolower(b) ? a : b));
    }
    
    

    return 0;
}