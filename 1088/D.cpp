#include <iostream>

using namespace std;

// クエリを投げる関数
int question(int c, int d) {
    cout << "? " << c << " " << d << endl;
    int ret;
    cin >> ret;
    return ret;
}

int main() {
    int c = 0, d = 0;

    // 現在のc, dでのa^cとb^dの大小関係を保持
    int stat = question(c, d);

    for (int k = 29; k >= 0; --k) {
        int ret = question(c + (1 << k), d + (1 << k));

        if (ret == stat) {
            // 大小関係に変化なし = k桁目は同じ

            int ret = question(c, d + (1 << k));
            if (ret == 1) {
                c += (1 << k);
                d += (1 << k);
            }
            // この更新で大小関係に変化はないのでstatはそのまま

        } else {
            // 大小関係が変化 = k桁目は異なる
            // 元の大小関係でどちらが1かが分かる
            if (stat == 1) {
                c += (1 << k);
            } else {
                d += (1 << k);
            }

            // この更新では大小関係が変化しうるのでstatも更新
            stat = question(c, d);
        }
    }

    cout << "! " << c << " " << d << endl;
    return 0;
}
