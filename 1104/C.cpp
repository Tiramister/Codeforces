#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int ver = 0, hol = 0;
    for (char c : S) {
        if (c == '0') {  // 縦タイル
            cout << 1 << " " << ver + 1 << endl;
            ver = (ver + 1) % 4;
        } else {  // 横タイル
            cout << 3 << " " << hol * 2 + 1 << endl;
            hol = (hol + 1) % 2;
        }
    }
    return 0;
}
