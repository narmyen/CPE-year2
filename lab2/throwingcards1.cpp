#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int n, x;

    string output;

    while (cin >> n, n) {
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        output += "Discarded cards: ";
        while (q.size() > 1) {
            output += to_string(q.front());
            q.pop();
            x = q.front();
            q.push(x);
            q.pop();
            if (q.size() == 1) {
                output += "\n";
            } else {
                output += ", ";
            }
        }
        output += "Remaining card: " + to_string(q.front()) + "\n";
        q.pop();
    }

    cout << output;

    return 0;
}
