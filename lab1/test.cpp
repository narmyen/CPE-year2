#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, t, now = 0, ans = 0;
    cin >> n >> k >> t;
    t--;
    

    do {
        ans++;
        now = (now + k) % n;
    } while (now != 0 && now != t);

    if (now == t) ans++;

    cout << ans;

    return 0;
}
