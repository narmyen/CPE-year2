#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    int ans[n];


    // append arr;

    arr[0] = n;
    for (int i = 1; i <= n; i++){
      cin >> arr[i];
    }

    if(k == 1){
      for (int j = 0; j < n; j++){
      if(j >= n - 1){
        break;
      }
      if(arr[j] > arr[j + 1]){
        cout << 0 << "\n";
      }
      else{
        cout << 1 << "\n";
      }
    }
    }


}
