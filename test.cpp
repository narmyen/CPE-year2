#include <iostream>
#include <map>
#include <vector>
using namespace std;

int findMax(const map<int, vector<int>>& statusLikes, int idx) {
    int maxVal = -99999;
    for (const auto& pair : statusLikes) {
        int currentVal = pair.second[idx];
        if (currentVal > maxVal) {
            maxVal = currentVal;
        }
    }
    return maxVal;
}

int findMaxKey(const map<int, vector<int>>& statusLikes, int idx) {
    int maxVal = -99999;
    int key = -1;
    for (const auto& pair : statusLikes) {
        int currentVal = pair.second[idx];
        if (currentVal > maxVal) {
            maxVal = currentVal;
            key = pair.first;
        }
    }
    return key;
}

int main() {
    int N;
    cin >> N;

    map<int, vector<int>> statusLikes;
    map<int, vector<int>> filter;
    vector<int> ans;

    for (int i = 0; i < N; ++i) {
        int action, status;
        cin >> action >> status;

        if (statusLikes.find(status) == statusLikes.end()) {
            statusLikes[status] = {0, 0};
        }

        if (action == 1) {
            statusLikes[status][0]++;
        } else {
            statusLikes[status][0]--;
        }
        statusLikes[status][1] = i + 1;

        int maxLikes = findMax(statusLikes, 0);
        int maxRound = findMax(statusLikes, 1);

        filter.clear();

        for (const auto& pair : statusLikes) {
            auto val = pair.second;
            if (val[0] == maxLikes) {
                filter[pair.first] = val;
            }
        }

        int maxKey = findMaxKey(filter, 1);
        ans.push_back(maxKey);
    }

    for (const auto& val : ans) {
        cout << val << "\n";
    }

    return 0;
}
