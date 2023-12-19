#include <iostream>
#include <list>
using namespace std;

list<int> l_price;
list<int> l_money;

int main(){
  int n, k;
  cin >> n >> k;

  for(int i = 0;i < n; i++){
    int u;
    cin >> u;
    l_price.push_back(u);
  }

  for(int i = 0; i < k; i++){
    int v;
    cin >> v;
    l_money.push_back(v);
  }

  l_price.sort();xx
  
  for(auto i = l_money.begin(); i != l_money.end(); i++){
    int money = *i;
    int count = 0;
    for(auto j = l_price.begin(); j != l_price.end(); j++){
      if(money >= *j){
        money -= *j;
        count++;
      }
      break;
    }
    cout << count << endl;
  }

}