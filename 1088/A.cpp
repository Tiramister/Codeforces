#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;

    if (x == 1) {
        // 解無し
        cout << -1 << endl;
    } else {
        // a = b = x
        cout << x << " " << x << endl;
    }
    return 0;
}
