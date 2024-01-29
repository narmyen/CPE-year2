#include <iostream>
#include <vector>

using namespace std;

string canMove(vector<string>& box, int N, int M) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < M - 1; ++j) {
            if (box[i][j] == '.' && box[i][j + 1] == '.' && box[i + 1][j] == '.' && box[i + 1][j + 1] == '.') {
                if (box[i + 2][j] == '.' && box[i + 2][j + 2] == '.') {
                    return "yes";
                }
                return "no";
            }
        }
    }
    return "no";
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> box(N);
    for (int i = 0; i < N; ++i) {
        cin >> box[i];
    }

    cout << canMove(box, N, M) << endl;

    return 0;
}
