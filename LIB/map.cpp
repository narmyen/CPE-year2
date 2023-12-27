// #include <iostream>
// #include <map>
// #include <string>
// using namespace std;

// int main(){

//   map<string, int> mp;

//   mp["one"] = 1;
//   mp["two"] = 2;
//   mp["tree"] = 3;

//   auto it = mp.begin();

//   while(it != mp.end()){
//     cout << "Key: " << it->first << ", Value: " << it->second << endl;
//     ++it;
//   }

//   Traverse the map
//     for (auto& it : Map) {
 
//         // If mapped value is K,
//         // then print the key value
//         if (it.second == K) {
//             cout << it.first << ' ';
//             a = false;
//         }
//     }

//   return 1;
// }



// BFS //

// #include <iostream>
// #include <map>
// #include <vector>
// #include <queue>
// #include <unordered_set>
// using namespace std;

// void bfs(const map<int, vector<int>>& graph, int start) {
//     queue<int> q;
//     unordered_set<int> visited;

//     q.push(start);
//     visited.insert(start);

//     while (!q.empty()) {
//         int current = q.front();
//         q.pop();

//         cout << current << " ";

//         for (int neighbor : graph.at(current)) {
//             if (visited.find(neighbor) == visited.end()) {
//                 q.push(neighbor);
//                 visited.insert(neighbor);
//             }
//         }
//     }
// }

// int main() {
//     // Example graph representation (adjacency list)
//     map<int, vector<int>> graph;
//     graph[1] = {2, 3};
//     graph[2] = {1, 4, 5};
//     graph[3] = {1, 6};
//     graph[4] = {2};
//     graph[5] = {2, 7};
//     graph[6] = {3};
//     graph[7] = {5};

//     // Start BFS from node 1
//     cout << "BFS starting from node 1: ";
//     bfs(graph, 1);

//     return 0;
// }
