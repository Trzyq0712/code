#include <bits/stdc++.h>
using namespace std;



double d, k;

double score = 60.0;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cin >> d >> k;

    // cout << score << "\n";
    score += (1.8 * (d - k));
    // cout << score << "\n";
    double mi = 21, mx = -1;
    double s = 0;
    for(int i = 0; i < 5; i++) {
        double p;
        cin >> p;
        score += p;
        s += p;
        mi = min(mi, p);
        mx = max(mx, p);
    }
    // cout << "mi " << mi << "mx" << mx << "\n";
    score -= mi;
    score -= mx;
    s -= mi;
    s -= mx;
    // cout << s << "\n";
    int b1, b2;
    cin >> b1 >> b2;
    score += (b2 - b1) * 3.2;
    // cout << "b " << (b2 - b1) * 3.2 << "\n";
    // cout << "sc " << score << "\n";
    double w;
    cin >> w;
    score += w;
    cout << score;
    return 0;
}