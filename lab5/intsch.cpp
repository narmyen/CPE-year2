#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

const int MAX_N = 100001;

int main() {
  pair<int, int> interval[MAX_N];
  int n, count = 1;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int start, end;
    cin >> start >> end;

    interval[i].first = start;
    interval[i].second = end;
  }

  pair<int, int> swap_interval[MAX_N];

  for (int i = 0; i < n; i++) {
    int end, start;
    end = interval[i].second;
    start = interval[i].first;

    swap_interval[i].first = end;
    swap_interval[i].second = start;
  }

  sort(swap_interval, swap_interval + n);

  // first is end_time
  // second is start_time
  int end_point;
  end_point  = swap_interval[0].first;
  for (int i = 1; i < n; i++) {
    int start_point = swap_interval[i].second;
    if (start_point >= end_point) {
      end_point = swap_interval[i].first;
      count++;
    }
  }

  cout << count;

  return 0;
}