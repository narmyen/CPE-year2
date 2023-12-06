#include <iostream>
using namespace std;

int count = 0;
int curr = 1;

void nextStep(int n, int k, int t) {
    int next;
    
    for (int i = 0; i < n; i++) {
        next = (curr + k) % n;
        if (next == 0) {
            next += n;
            count++;
            curr = next;
            continue;
        } else if (next == 1 || next == t) {
            count++;
            break;
        }
        curr = next;
        count++;
    }

    cout << count;
}

int main() {
    int n, k, t;
    cin >> n >> k >> t;

    nextStep(n, k, t);
    return 0;
}
