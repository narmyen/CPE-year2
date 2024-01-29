#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

const int MAX_N = 100010;

int m, n;
vector<int> adj[MAX_N];
int deg[MAX_N];

bool seen[MAX_N];
int layer[MAX_N];
int color[MAX_N];

void init() {
    for (int u = 0; u < n; u++) {
        seen[u] = false;
        layer[u] = -1;
        color[u] = -1;
    }
}

bool bfs(int s) {
    list<int> Q;

    Q.push_back(s);
    seen[s] = true;
    layer[s] = 0;
    color[s] = 0;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop_front();
        for (int d = 0; d < deg[u]; d++) {
            int v = adj[u][d];
            if (!seen[v]) {
                Q.push_back(v);
                seen[v] = true;
                layer[v] = layer[u] + 1;
                color[v] = 1 - color[u];
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }

    return true;
}

void clearGraph() {
    for (int i = 0; i < MAX_N; i++) {
        adj[i].clear();
        deg[i] = 0;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        deg[i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    init();
    bool bipartite = true;

        for (int u = 0; u < n; u++) {
            if (!seen[u]) {
                for(int i = 0; i < deg[u]; i++){
                  adj[u].pop_front();
                  adj[i].pop_front();

                  bipartite = bfs(u);
                  if (!bipartite) {
                      break;
                  }

                  adj[u].push_back();
                  adj[i].push_back();
                }
            }
        }

        if (bipartite) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
        clearGraph();

    return 0;
}
