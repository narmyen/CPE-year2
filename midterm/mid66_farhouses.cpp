#include<iostream>
#include<algorithm>
#define MAX_N 100009
using namespace std;

int main(){
  int interval[MAX_N];
  int position[MAX_N];

  int n, k, l;
  cin >> n >> k >> l;

  for(int i = 0; i < n; i++){
    cin >> position[i];
  }
  
  for(int i = 0; i < n; i++){
    interval[i] = 0;
  }

  sort(position, position + n);
  
//   for(int i = 0; i < n; i++){
//       cout << position[i];
//   }

  int max = -999999;
  
  for(int i = 0; i < n; i++){
    int last_positionAdd = i + k + l;

    if(last_positionAdd <= n){
      for(int j = i + 1; j <= last_positionAdd; j++ ){
        interval[i] = position[j] - position[i];
      }
    }
    
    if(interval[i] >= max){
        max = interval[i];
    }
  }

//   for(int i = 0;i < n; i++){
//     cout << interval[i] << " ";
//   }

  cout << max << "\n";

  return 0;
}