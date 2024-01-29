#include<iostream>
#include<vector>
#include<stack>
#define MAX_NODE 100001
using namespace std;

bool visited[MAX_NODE];
vector<int> adj[MAX_NODE], ans_01;
int inDeg[MAX_NODE];
stack<int> ans;

void dfs(int p) {
    visited[p] = true;
    for (int q : adj[p]) {
        if (!visited[q]) {
            dfs(q);
        }
    }
    ans.push(p);
}

int main() {
    int n, m;
    int a, b;
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        inDeg[b]++;
        adj[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    while (!ans.empty()) {
        int curr = ans.top();
        ans_01.push_back(curr);
        ans.pop();
        if (inDeg[curr]) {
            cout << "no\n";
            return 0;
        }
        for (auto x : adj[curr]) {
            inDeg[x]--;
        }
    }
    for (auto x : ans_01) {
        cout << x + 1 << "\n";
    }

    return 0;
}
