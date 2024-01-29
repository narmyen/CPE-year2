#include <iostream>
#include <map>
using namespace std;

map<int, int> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n;

    int maxKey = 0;
    for(int i = 0; i < n;i ++){
        cin >> x;
        m[x]++;
        if(m[x] >= m[maxKey]){
            maxKey = x;
        }
        cout << maxKey << "\n";
    }
}
