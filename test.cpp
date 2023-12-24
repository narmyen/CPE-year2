#include <iostream>
#include <iterator>
#include <vector>
#include <set>
using namespace std;

int main() {
    set<int> X;
    vector<int> Y;

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        X.insert(tmp);
    }

    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        Y.push_back(tmp);
    }

    for (auto &val : X) {
        cout << "X: " << val << endl;
    }

    cout << endl;

    for (int i = 0; i < M; i++) {
        cout << "Y: " << Y[i] << endl;
    }

    for (int i = 0; i < M; i++) {
        int tmp;
        tmp = Y[i];
        X.insert(tmp);
    }

    cout << endl;

    for (auto &val : X) {
        cout << "X new: " << val << endl;
    }

    for (auto &val : X) {
        for (int i = 0; i < M; i++) {
            if (val == Y[i]) {
                auto lower = X.lower_bound(val);
                auto upper = X.upper_bound(val);

                if (lower != X.begin()) {
                    lower--; // Move to the element before lower_bound
                    cout << *lower << ", ";
                } else {
                    cout << "*, "; // Indicates no element before
                }

                if (upper != X.end()) {
                    cout << *upper << endl;
                } else {
                    cout << "*\n"; // Indicates no element after
                }
            }
        }
    }

    return 0;
}
