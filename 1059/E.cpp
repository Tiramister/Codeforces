#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int N, L;
ll S;
vector<int> path[100010];

ll upcost[100010][20];  // iを末端とする、長さ2^kのパスの重み
int upto[100010][20];   // iからの距離が2^kの祖先

int ans = 0;

int dfs(int v) {
    int up = 0;  // 各子を含む集合の「あといくつ含めるか」の最大値
    for (int sv : path[v]) up = max(up, dfs(sv));

    if (up > 0) {
        // 頂点vはこの集合に加える
        ans += path[v].size() - 1;
        return up - 1;

    } else {
        // 頂点vは新たな集合にする
        ans += path[v].size();

        int ret = 0;  // vを末端とする集合の最大可能サイズ
        ll cost = 0;
        while (v > 0) {
            int k;
            for (k = 19; k >= 0; --k) {
                if (upcost[v][k] + cost <= S) break;
            }
            if (k < 0) break;  // 1つでも増やすとコストオーバー

            ret += (1 << k);
            cost += upcost[v][k];
            v = upto[v][k];
        }
        return min(L, ret) - 1;
    }
}

int main() {
    cin >> N >> L >> S;
    for (int i = 0; i < N; ++i) {
        cin >> upcost[i][0];
        if (upcost[i][0] > S) {
            cout << -1 << endl;
            return 0;
        }
    }

    upto[0][0] = -1;
    for (int i = 1; i < N; ++i) {
        cin >> upto[i][0];
        path[--upto[i][0]].push_back(i);
    }

    for (int k = 1; k < 20; ++k) {
        for (int i = 0; i < N; ++i) {
            upto[i][k] = upto[i][k - 1];
            upcost[i][k] = upcost[i][k - 1];

            if (upto[i][k - 1] >= 0) {
                upto[i][k] = upto[upto[i][k - 1]][k - 1];
                upcost[i][k] += upcost[upto[i][k - 1]][k - 1];
            }
        }
    }

    dfs(0);
    // 頂点0の集合を加える
    cout << ans + 1 << endl;
    return 0;
}
