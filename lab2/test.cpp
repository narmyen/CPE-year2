#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <list>

using namespace std;
list<int> myList[100099];

int main(){
  int n;
  char c;
  int i , j;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> c >> i >> j;
    if(c == 'N'){
      myList[j].push_back(i);
    }
    else if(c == 'M'){
      myList[j].splice(myList[j].end(), myList[i]);
    }
  }

  for(int j = 0; j < 100099; j++){
    if(myList[j].size() == 0) continue;
    else{
      for (it = myList.begin(); it != myList.end(); ++it)
        cout << '\t' << *it;
      cout << '\n';
    }
  }

  return 1;
}