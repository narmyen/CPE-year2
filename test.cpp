#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v_price;
vector<int> v_money;

int main() {
  int n, k;
  cin >> n >> k;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    sum += u;
    v_price.push_back(sum);
  }

  for (int i = 0; i < k; i++) {
    int v;
    cin >> v;
    v_money.push_back(v);
  }


  for (auto i = v_money.begin(); i != v_money.end(); i++) {
    auto low = lower_bound(v_price.begin(), v_price.end(), *i);
    cout << low - v_price.begin() << endl;
  }

  return 0;
}
