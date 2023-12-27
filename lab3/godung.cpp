// complete

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int M;
    cin >> M;

    map<int, int> inventory;
    vector<int> ans;

    for (int i = 0; i < M; ++i) {
        int command;
        cin >> command;

        if (command == 1) {
            int A, B;
            cin >> A >> B;
            inventory[A] += B;
        } else if (command == 2) {
            int A;
            cin >> A;
            ans.push_back(inventory[A]);
        } else if (command == 3) {
            int A, B;
            cin >> A >> B;
            if(B > inventory[A]){
                ans.push_back(inventory[A]);
                inventory[A] = 0;
            }
            else{
                inventory[A] -= B;
                ans.push_back(B);
            }
        }
    }

    for (const auto& val : ans) {
        cout << val << "\n";
    }

    return 0;
}
