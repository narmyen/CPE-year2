#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& mangaPrice, int target) {
    int low = 0;
    int high = mangaPrice.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (mangaPrice[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> mangaPrice(N);
    vector<int> money(K);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        mangaPrice[i] = sum;
    }

    for (int i = 0; i < K; ++i) {
        cin >> money[i];
    }

    for (int i = 0; i < K; i++) {
        int index = binarySearch(mangaPrice, money[i]);
        cout << index << endl;
    }

    return 0;
}
