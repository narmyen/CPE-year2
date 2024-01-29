#include <iostream>
#include <stack>
#include <string>
using namespace std;

const int MAX_N = 1001;
int arr[MAX_N];
string ans[MAX_N];

int main() {
    int n;
    int ansIdx = 0;
    while (true) {
        cin >> n;
        if (n == 0) break;

        while (true) {
            cin >> arr[0];
            if (arr[0] == 0) {
                // cout << "\n";
                ans[ansIdx++] = "";
                break;
            }

            for (int i = 1; i < n; i++) {
                cin >> arr[i];
            }

            stack<int> st;
            int idx = 0;

            for (int i = 1; i <= n; i++) {
                st.push(i);

                while (!st.empty() && st.top() == arr[idx]) {
                    st.pop();
                    idx++;
                    if (idx >= n) break;
                }
            }

            if (st.empty()) {
                ans[ansIdx++] = "Yes";
            } else {
                ans[ansIdx++] = "No";
            }
        }
    }

    for (int i = 0; i < ansIdx; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
