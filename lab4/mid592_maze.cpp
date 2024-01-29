#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isValid(int row, int col, int N) {
    return (row >= 0 && row < N && col >= 0 && col < N);
}

bool canReach(vector<vector<char>> &maze, int sRow, int sCol, int dRow, int dCol) {
    int count_o = 0;
    int N = maze.size();
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    queue<pair<int, int>> q;
    q.push(make_pair(sRow, sCol));
    visited[sRow][sCol] = true;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        if (current.first == dRow && current.second == dCol) {
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int newRow = current.first + dr[i];
            int newCol = current.second + dc[i];
            if (isValid(newRow, newCol, N) && !visited[newRow][newCol]) {
                if (maze[newRow][newCol] == '.') {
                    q.push(make_pair(newRow, newCol));
                    visited[newRow][newCol] = true;
                } else if (maze[newRow][newCol] == 'O' && count_o == 0) {
                    q.push(make_pair(newRow, newCol));
                    visited[newRow][newCol] = true;
                    count_o++;
                }
            }
        }
    }

    return false;
}

vector<int> ans;
int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<char>> maze(N, vector<char>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> maze[i][j];
        }
    }

    for (int i = 0; i < Q; ++i) {
        int sRow, sCol, dRow, dCol;
        cin >> sRow >> sCol >> dRow >> dCol;

        --sRow;
        --sCol;
        --dRow;
        --dCol;

        if (canReach(maze, sRow, sCol, dRow, dCol)) {
            ans.push_back(1);
        } else {
            ans.push_back(0);
        }
    }

    for(auto x: ans){
      if(x){
        cout << "yes" << "\n";
      }
      else{
        cout << "no" << "\n";
      }
    }

    return 0;
}
