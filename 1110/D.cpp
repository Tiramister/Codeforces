#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int cnt[m];
    fill(cnt, cnt + m, 0);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++cnt[--a];  // 0-indexedに変換
    }

    int dp[m + 1][5][3];
    fill(dp[0][0], dp[m + 1][0], 0);

    for (int i = 0; i < m; ++i) {
        for (int p = 0; p < 5; ++p) {
            for (int q = 0; q < 3; ++q) {
                for (int s = 0; s < 3; ++s) {
                    if (p + s > cnt[i]) continue;  // 牌が足りない
                    int c = (cnt[i] - p - s) / 3;  // 作れる刻子の数
                    dp[i + 1][q + s][s] = max(dp[i + 1][q + s][s], dp[i][p][q] + s + c);
                }
            }
        }
    }

    cout << dp[m][0][0] << endl;
    return 0;
}
