#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int MAX_N = 100010;

int m, n;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input(){
  cin >> n >> m;
  for(int i = 0; i < n; i++) deg[i] = 0;

  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
}

bool visited[MAX_N];
int component[MAX_N]; 
int component_count = 0;

void init(){
  for(int u = 0; u < n; u++){
    visited[u] = false;
    component[u] = -1;
  }
}

void bfs(int val){
  list<int> q;

  q.push_back(val);
  visited[val] = true;
  component[val] = component_count;

  while(!q.empty()){
    int u = q.front();
    q.pop_front();
    for(int d = 0; d < deg[u]; d++){
      int v = adj[u][d];
      if(!visited[v]){
        q.push_back(v);
        visited[v] = true;
        component[v] = component_count;
      }
    }
  }
}

void find_connected_components(){
  for(int u = 0; u < n; u++){
    if(!visited[u]){
      bfs(u);
      component_count++;
    }
  }
}

int main(){
  read_input();
  init();
  find_connected_components();

//   for(int u = 0; u < n; u++){
//     cout << u+1 << " " << component[u] + 1 << endl;
//   }

  cout << component_count << endl;
}
