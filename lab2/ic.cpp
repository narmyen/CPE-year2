#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <string>
using namespace std;


int main(){
  list<int> list;

  int n, value;
  string s;

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> s;
    if(s == "li"){
      cin >> value;
      list.push_front(value);
    }
    else if(s == "ri"){
      cin >> value;
      list.push_back(value);
    }
    else if(s == "lr"){
      list.push_back(list.front());
      list.pop_front();
    }
    else if(s == "rr"){
      list.push_front(list.back());
      list.pop_back();
    }
  }

  for(auto i = list.begin(); i != list.end(); i++){
    cout << *i << "\n";
  }  
}