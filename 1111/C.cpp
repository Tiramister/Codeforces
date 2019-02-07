#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int n, k, a, b;
int p[100010];

ll rec(ll l, ll r) {
    // 区間内のa_iの数
    ll num = upper_bound(p, p + k, r) - upper_bound(p, p + k, l);

    if (num == 0) return a;          // 空区間をスキップ
    if (r - l == 1) return b * num;  // 長さが1のときは、終了しないと無限ループになる

    // 2つの区間に分割
    int m = (l + r) / 2;
    return min(b * num * (r - l), rec(l, m) + rec(m, r));
}

int main() {
    cin >> n >> k >> a >> b;
    for (int i = 0; i < k; ++i) cin >> p[i];
    sort(p, p + k);

    cout << rec(0, 1 << n) << endl;
    return 0;
}
