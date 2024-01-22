#include<bits/stdc++.h>
#include <vector>
#define MAX_M 200009
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;

  int arr_y[MAX_M];
  vector<int> arr_x;

  for(int i = 0; i < n; i++){
    int val;
    cin >> val;
    arr_x.push_back(val);
  }

  sort(arr_x.begin(), arr_x.end());

  for(int i = 0; i < m; i++){
    cin >> arr_y[m];
  }


  // for(int i = 0; i < m; i++){
  //   int 
  // }
  return 0;
}