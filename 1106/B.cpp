#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;

    ll a[n], c[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> c[i];

    int order[n];
    iota(order, order + n, 0);
    sort(order, order + n,
         [&](int i, int j) { return c[i] < c[j]; });

    int itr = 0;
    for (int i = 0; i < m; ++i) {
        int t;
        ll d;
        cin >> t >> d;
        --t;
        ll ans = 0;

        while (d > 0 && itr < n) {
            ll g = min(d, a[t]);  // tを出せる最大枚数
            ans += c[t] * g;
            d -= g, a[t] -= g;

            if (t != order[itr]) {
                t = order[itr];  // 最初だけ例外処理
            } else if (a[t] == 0) {
                t = order[++itr];  // 次に安い料理へ
            }
        }

        // d > 0なら客は怒って帰ったので0
        cout << (d == 0 ? ans : 0) << endl;
    }
    return 0;
}
