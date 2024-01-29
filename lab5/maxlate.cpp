#include<iostream>
#include<algorithm>
#include <vector>
#define MAX_N 100009
using namespace std;

struct iv {
    int deadline;
    int time;
    
    friend bool operator<(const iv& l, const iv& r)
    {
        return l.deadline < r.deadline;
    }
};

iv intervals[MAX_N];
vector<int> arr;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i].deadline >> intervals[i].time;
    }

    sort(intervals, intervals + n);

    int lateness = 0;
    int start_time = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
      lateness = (intervals[i].time + start_time)-intervals[i].deadline;
      start_time += intervals[i].time;

      if(lateness > 10){
        arr.push_back(lateness);
      }
    }

    if (!arr.empty()) {
        int maxLateness = *max_element(arr.begin(), arr.end());
        cout << (maxLateness-10)*1000 << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}
