#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
  list<int> l;
  list<int> sorted;

  int n,x;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> x;
    l.push_back(x);
  }
  
  cout << "List contents: ";
  for (auto it = l.begin(); it != l.end(); ++it) {
    cout << *it << " ";
  }
  cout << "\n";

  list<int> result;
  auto it = l.begin();
  while (it != prev(l.end())) {
      result.push_back(*it + *next(it));
  }

  for (auto it = result.begin(); it != result.end(); ++it) {
    cout << *it << " ";
  }



}