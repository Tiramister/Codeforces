#include <iostream>

using namespace std;

const int R = 666;
pair<int, int> rook[R];

// (tox, toy)に最も近づくように移動
void moveto(int& x, int& y, int tox, int toy) {
    int dx = (tox > x ? 1 : (tox < x ? -1 : 0));
    int dy = (toy > y ? 1 : (toy < y ? -1 : 0));

    x += dx, y += dy;
    for (int k = 0; k < R; ++k) {
        if (rook[k] == make_pair(x, y)) {
            x -= dx;
            break;
        }
    }
    cout << x << " " << y << endl;
}

// rookの移動を受け取る
void moverook() {
    int k, x, y;
    cin >> k >> x >> y;
    if (k <= 0) exit(0);
    rook[k - 1] = make_pair(x, y);
}

int main() {
    int x, y;
    cin >> x >> y;

    for (int i = 0; i < R; ++i) {
        cin >> rook[i].first >> rook[i].second;
    }

    // まずは中央(500, 500)に移動する
    int tox = 500, toy = 500;
    while (x != tox || y != toy) {
        moveto(x, y, tox, toy);
        moverook();
    }

    // 各エリアについて、利きがあるルークの数
    int cnt[2][2] = {{R, R}, {R, R}};
    for (int k = 0; k < R; ++k) {
        // 反対側のエリアには利きがないので減らす
        --cnt[rook[k].first < 500][rook[k].second < 500];
    }

    // 最も利きの多いエリアを探る
    int mi = 0, mj = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (cnt[i][j] > cnt[mi][mj]) {
                mi = i;
                mj = j;
            }
        }
    }

    // そのエリアの隅を目的地に指定
    tox = mi * 998 + 1;
    toy = mj * 998 + 1;

    while (x != tox || y != toy) {
        moveto(x, y, tox, toy);
        moverook();
    }

    return 0;
}
