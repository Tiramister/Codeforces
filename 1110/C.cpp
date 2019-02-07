#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int t = 0; t < q; ++t) {
        int a;
        cin >> a;

        int k;
        for (k = 30; k >= 0; --k) {
            if ((a >> k) & 1) break;
        }

        int ans = (1 << (k + 1)) - 1;

        if (a != ans) {
            cout << ans << endl;
        } else {
            // aのa未満で最大の約数が答え
            ans = 1;
            for (int i = 2; i * i <= a; ++i) {
                if (a % i == 0) {
                    ans = a / i;
                    break;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
