#include <iostream>

using namespace std;

void answer(int x) {
    cout << "! " << x << endl;
}

// (x, y)でクエリを投げ、xならtrueを返す
bool query(int x, int y) {
    cout << "? " << x << " " << y << endl;

    char res;
    cin >> res;
    return res == 'x';
}

void solve() {
    // 前半
    int k;
    for (k = 0; k < 30; ++k) {
        // (2^k-1, 2^(k+1)-1)でクエリを投げ、xが来たら終了
        if (query((1 << k) - 1, (1 << (k + 1)) - 1)) break;
    }

    // 後半
    int l = (1 << k) - 1, r = (1LL << (k + 1)) - 1;
    // a in (l, r]
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (query((1 << k) - 1, mid)) {
            // (2^k, mid)でxが来た <-> a <= mid
            r = mid;
        } else {
            l = mid;
        }
    }

    answer(r);
}

int main() {
    while (true) {
        string S;
        cin >> S;

        if (S == "start") {
            solve();
        } else {
            break;
        }
    }
    return 0;
}
