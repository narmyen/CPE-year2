//compete

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    int misses = 0;

    unordered_set<int> set_cache;
    queue<int> q_order;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;

        if (set_cache.count(val) == 0) {
            ++misses;

            if (set_cache.size() == n) {
                int tmp = q_order.front();
                q_order.pop();
                set_cache.erase(tmp);
            }

            set_cache.insert(val);
            q_order.push(val);
        }
    }

    cout << misses << endl;

    return 0;
}
