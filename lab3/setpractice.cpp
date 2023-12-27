// clear
#include <iostream>
#include <set>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    set<int> X;
    vector<int> ans;

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        X.insert(tmp);
    }

    for (int i = 0; i < M; i++) {
        int query;
        cin >> query;

        auto found = X.find(query);

        if (found != X.end()) {
            ans.push_back(query);
        } else {
            auto lower = X.lower_bound(query);

            if (lower != X.begin()) {
                lower--;
            }

            auto upper = X.upper_bound(query);

            if (lower == X.end()) {
                ans.push_back(*upper);
            } else if (upper == X.end()) {
                ans.push_back(*lower);
            } else {
                int diff_low = abs(query - *lower);
                int diff_high = abs(*upper - query);

                if (diff_low == diff_high || diff_low < diff_high) {
                    ans.push_back(*lower);
                } else {
                    ans.push_back(*upper);
                }
            }
        }
    }

    for (int i = 0; i < M; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

#include <iostream>
//complete

#include <set>
#include <cmath>
#include <vector>
using namespace std;

int binarySearch(const set<int>& X, int query) {
    auto it = X.lower_bound(query);
    if (it == X.begin()) {
        return *it;
    }
    if (it == X.end()) {
        return *(--it);
    }
    int lower = *it;
    --it;
    int upper = *it;
    return abs(query - lower) < abs(query - upper) ? lower : upper;
}


// binary method
// int main() {
//     set<int> X;
//     vector<int> ans;

//     int N, M;
//     cin >> N >> M;

//     for (int i = 0; i < N; i++) {
//         int tmp;
//         cin >> tmp;
//         X.insert(tmp);
//     }

//     for (int i = 0; i < M; i++) {
//         int query;
//         cin >> query;

//         auto found = X.find(query);

//         if (found != X.end()) {
//             ans.push_back(query);
//         } else {
//             int closest = binarySearch(X, query);
//             ans.push_back(closest);
//         }
//     }

//     for (int i = 0; i < M; i++) {
//         cout << ans[i] << endl;
//     }

//     return 0;
// }

