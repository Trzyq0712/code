#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 15;

int n;
int A[2 * N];

vector <pair <int, int> > v;

int sw(int a, int b) {
    int mxdf = -1;
    vector <int> idx;

    swap(A[a], A[b]);
    // cout << "a:" << a << " b: " << b << "\n";

    if(a != 1) {
        idx.push_back(a - 1);
        mxdf = max(mxdf, abs(A[a] - A[a - 2]));
        // cout << a - 1 << " " << abs(A[a] - A[a - 2]) << "\n";
    }
    if(b != 1) {
        idx.push_back(b - 1);
        mxdf = max(mxdf, abs(A[b] - A[b - 2]));
        // cout << b - 1 << " " << abs(A[b] - A[b - 2]) << "\n";
    }
    if(a != 2 * n - 1) {
        idx.push_back(a + 1);
        mxdf = max(mxdf, abs(A[a] - A[a + 2]));
        // cout << a + 1 << " " << abs(A[a] - A[a + 2]) << "\n";
    }
    if(b != 2 * n - 1) {
        idx.push_back(b + 1);
        mxdf = max(mxdf, abs(A[b] - A[b + 2]));
        // cout << b + 1 << " " << abs(A[b] - A[b + 2]) << "\n";
    }

    // cout << "mxdf: " << mxdf << "\n";

    swap(A[a], A[b]);

    for(auto x : v) {
        int i = x.second;
        auto l = find(idx.begin(), idx.end(), i);
        if(l == idx.end()) {
            return max(mxdf, x.first);
        }
    }
    return mxdf;
}



int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    cin >> n;
    cin >> A[1];
    if(n == 1) {
        cout << 0;
        return 0;
    }
    int mx = -1, mx_diff = -1;
    for(int i = 3; i < 2 * n; i += 2) {
        cin >> A[i];
        A[i - 1] = abs(A[i - 2] - A[i]);
        if(abs(A[i - 1]) > mx_diff) {
            mx = i - 1;
            mx_diff = abs(A[i - 1]);
        }
        v.push_back({A[i - 1], i - 1});
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    // for(auto x : v) {
    //     printf("{%d, %d}  ", x.first, x.second);
    // }

    // int c = 0;
    // for(int i = 2; i < 2 * n; i++) {
    //     if(abs(A[i]) == mx_diff) c++;
    // }
    // if(c > 1) {
    //     cout << mx
    // }

    for(int i = 1; i < 2 * n; i += 2) {
        int a1 = mx - 1, a2 = mx + 1, b = i;
        // int x = mx_diff;
        mx_diff = min(mx_diff, min(sw(a1, b), sw(a2, b)));
        // if(x != mx_diff) cout << mx << ' ' << b << '\n';
    }
    cout << mx_diff;
    // cout << mx << ' ' << mx_diff;
    return 0;
}