#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

class UnionFind {
public:
    int V_NUM;
    vector<int> par, num;

    explicit UnionFind(int N) : V_NUM(N) {
        par.resize(N);
        iota(par.begin(), par.end(), 0);
        num.assign(N, 1);
    }

    int find(int x) {
        return (par[x] == x) ? x : (par[x] = find(par[x]));
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;

        if (num[x] < num[y]) swap(x, y);
        num[x] += num[y];
        par[y] = x;
    }

    bool same(int x, int y) { return find(x) == find(y); }
    bool ispar(int x) { return x == find(x); }
    int size(int x) { return num[find(x)]; }
};

void fail() {
    cout << "No" << endl;
    exit(0);
}

vector<set<int>> path;
vector<int> ans;
vector<bool> visited;

// 子の中で一番大きいスコア+1を割り振る
void dfs(int v) {
    if (ans[v] > 0) return;  // 前の週で探索済み

    visited[v] = true;
    ans[v] = 1;
    for (int sv : path[v]) {
        if (visited[sv]) fail();  // ループ判定
        dfs(sv);
        ans[v] = max(ans[v], ans[sv] + 1);
    }
    visited[v] = false;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (auto& s : S) cin >> s;

    // =で結ばれた料理を結ぶ
    UnionFind uf(N + M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (S[i][j] == '=') uf.unite(i, j + N);
        }
    }

    // =の関係に矛盾がないか判定
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (uf.same(i, j + N) && S[i][j] != '=') fail();
        }
    }

    // 大小関係に応じて辺を張る
    // ただしUnionFindに於ける根の間にしか張らない
    path.resize(N + M);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (S[i][j] == '>') {
                path[uf.find(i)].insert(uf.find(j + N));
            } else if (S[i][j] == '<') {
                path[uf.find(j + N)].insert(uf.find(i));
            }
        }
    }

    // DFSでスコアを振っていく
    ans.assign(N + M, -1);
    visited.assign(N + M, false);
    for (int v = 0; v < N + M; ++v) {
        if (uf.ispar(v)) dfs(v);
    }

    cout << "Yes" << endl;
    for (int i = 0; i < N; ++i) {
        cout << ans[uf.find(i)] << " ";
    }
    cout << endl;
    for (int j = 0; j < M; ++j) {
        cout << ans[uf.find(j + N)] << " ";
    }
    cout << endl;
    return 0;
}
