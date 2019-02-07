#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    a[N] = 0;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    // これでaから重複要素が消える

    for (int k = 0; k < K; ++k) {
        if (k < a.size() - 1) {
            cout << a[k + 1] - a[k] << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
