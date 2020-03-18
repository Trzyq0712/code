#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 15;
const int R = 1e5 + 15;

int n, k, r;

bool discovered[N];

struct reaction {
    int r_count;
    vector <int> products;
};

reaction reactions[R];

vector <int> G[N];

int main() {
    scanf("%d %d %d", &n, &k, &r);

    queue <int> subs;
    for(int i = 0; i < k; i++) {
        int sub;
        scanf("%d", &sub);
        discovered[sub] = 1;
        subs.push(sub);
    }

    for(int i = 1; i <= r; i++) {
        int a, b;
        scanf("%d", &a);
        reactions[i].r_count = a;
        while(a--  > 0) {
            int x;
            scanf("%d", &x);
            G[x].push_back(i);

        }
        scanf("%d", &b);
        while(b-- > 0) {
            int x;
            scanf("%d", &x);
            reactions[i].products.push_back(x);
        }
    }

    while(!subs.empty()) {
        int x = subs.front();
        subs.pop();
        for(int y : G[x]) {
            if(--reactions[y].r_count == 0) {
                for(int sub : reactions[y].products) {
                    if(discovered[sub]) continue;
                    subs.push(sub);
                    discovered[sub] = 1;
                }
            }

        }
    }

    int res = 0;

    for(int i = 1; i <= n; i++) {
        if(discovered[i])
            res++;
    }

    printf("%d", res - k);

    return 0;
}