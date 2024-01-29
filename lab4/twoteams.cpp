#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

const int MAX_N = 100010;

int m, n;
vector<int> adj[MAX_N];
int deg[MAX_N];

void read_input() {
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
}

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
    int n;
    cin >> n;
    vector<string> ans;

    for(int i = 0; i < n; i++){
        read_input();
        init();

        bool bipartite = true;

        for (int u = 0; u < n; u++) {
            if (!seen[u]) {
                bipartite = bfs(u);
                if (!bipartite) {
                    break;
                }
            }
        }

        if (bipartite) {
            ans.push_back("yes");
        } else {
            ans.push_back("no");
        }
        clearGraph();

    }

    for(string ans: ans) {
        cout << ans << "\n";
    }

    return 0;
}
