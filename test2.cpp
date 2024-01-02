#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 1005;

struct Point {
    int x, y;
};

int n, R;
Point points[MAX_N];

bool canJump(int x, int y, int jumpRadius) {
    return (x >= 0 && x <= 100 && y >= 0 && y <= 100 && pow(x - 50, 2) + pow(y, 2) > pow(50 - jumpRadius, 2));
}

int main() {
    cin >> n >> R;

    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int low = 0, high = 100;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        bool valid = true;

        for (int i = 0; i < n; i++) {
            if (!canJump(points[i].x, points[i].y, mid)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}
