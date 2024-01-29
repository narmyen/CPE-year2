#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_K = 109;
const int MAX_N = 1009;

int main() {
  struct RecordInfo{
    int c;
    int p;
    int w;
  };

  RecordInfo all_record[MAX_K];
  int adder[MAX_N];

  int k, n;
  cin >> k >> n;

  for(int i = 0; i < k; i++){
    cin >> all_record[i].c >> all_record[i].p >> all_record[i].w; 
  }

  int mx=-2e9;
  for(int i = 0; i < n; i++){
    cin >> adder[i]; 
    mx = max(mx,adder[i]);
  }

  int mn = 2e9;
  for(int i =0 ; i < k; i++){
    int c = all_record[i].c;
    int p = all_record[i].p;
    int w = all_record[i].w;
    int sum = 0;
    int count = 1;

    if(mx > w){
      // another record
      continue;
    }

    for(int j = 0; j < n; j++){
      sum += adder[j];
      if(sum > w){
        // the last is adder[j] for add in another group that be the first of adder
        sum = adder[j];
        count++;
      }
    }

    // GREEDY : find the min and then assign the best answer
    mn = min(mn, c + (count * p));
  }

  cout << mn;

  return 0;
}