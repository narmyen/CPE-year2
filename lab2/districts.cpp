#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> arr;
set<int> ans;
bool visited[101];
int sortArr[101];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 101; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
        visited[i] = true;
    }

    for (int start = 0; start < n; start++) {
        int sum = 0;
        for (int i = start; i < n; i++) {
            sum += arr[i];
            ans.insert(sum);
        }
    }

    // auto it = ans.begin();
    // while (it != ans.end()) {
    //     cout << *it << " ";
    //     ++it;
    // }

    cout << ans.size() << endl;

    return 0;
}
