#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

    

    for(int i = 0; i < K; i++){
      for(int j = 0; j < N; j++){
        if(money[i] < mangaPrice[j]){
          cout << j << endl;
          break;
        }
        continue;
      }
    }

    return 0;
}
