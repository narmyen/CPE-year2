#include <iostream>
using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    t--;

    int now = 0, ans;
    

    for (ans = 1; now != 0 && now != t; ans++) {
        now = (now + k) % n;
    }

    if (now == t) ans++;

    cout << ans;

    return 0;
}
