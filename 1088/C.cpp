#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    cout << N + 1 << endl;
    // 操作数はN+1で固定

    cout << 1 << " " << N << " " << 500000 << endl;
    // 最初に全要素に500000を足してしまう

    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        a += 500000;

        // aをiにしたい
        // aが十分大きいのでa - iで割ってしまえばいい
        cout << 2 << " " << i + 1 << " " << a - i << endl;
    }
    return 0;
}
