#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(){
  list<int> list;

  int m, value;
  char c;

  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> c >> value;

    if(c == 'I'){
      list.push_front(value);
    }
    else if(c == 'D'){
      // list.erase(l.begin());
      // remove first value

      auto l = list.begin();
      for (int i = 0; i < value-1 ; i++){
        if(l == list.end()) continue;
        l++;
      }
      if(l != list.end()){
        list.erase(l);
      }
    }
  }

  for(auto i = list.begin(); i != list.end(); i++){
    // auto i 
    cout << *i << "\n";
  }  
}