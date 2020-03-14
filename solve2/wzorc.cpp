#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 5e5 + 15;

int A[N], B[N];

int n;

vector <LL> divs;

// void primeDivs

void factor(LL x, vector<LL> &res){
  for(LL i = 2;i * i <= x;i++){
    if(x % i == 0){
      res.push_back(i);
      factor(x / i, res);
      return;
    }
  }
  res.push_back(x);
}

int main() {
    scanf("%d", &n);

    LL sum = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
        sum += (LL)B[i];
    }

    
    // LL s = sum;
    // for(LL i = 2; i <= sqrt(sum); i++) {
    //     while(s % i == 0) {
    //         s /= i;
            
    //     }
    // }
    // divs.insert(sum);

    factor(sum, divs);

    int mn = INT_MAX;


    for(LL div : divs) {
        // printf("%lld\n", div);

        for(int i = 0; i < N; i++) 
            A[i] = B[i];

        int ch = 0;
        for(int i = 0; i < n - 1; i++) {
            if((LL)A[i] % div == 0) continue;
            A[i + 1] += A[i];
            ch++;
        }
        // printf("ch: %d\n", ch);
        mn = min(ch, mn);
    }
    

    

    printf("%d", mn);


}