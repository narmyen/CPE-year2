#include <iostream>
using namespace std;


int count = 0;

int countLower(int arr[], int n) {
    if (n == 1) {
        return count;
    }

    int tmp = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > tmp) {
            count++;
        }
    }

    return countLower(arr + 1, n - 1);
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = countLower(arr, n);
    cout << result << "\n";

    return 0;
}
