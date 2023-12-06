#include <iostream>
#include <list>

using namespace std;

list<int> myList[100099];

int main() {
    int n;
    char c;
    int i, j;

    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> c >> i >> j;
        if (c == 'N') {
            myList[j].push_back(i);
        } else if (c == 'M') {
            myList[j].splice(myList[j].end(), myList[i]);
        }
    }

    for (int j = 0; j < 100099; j++) {
        if (myList[j].size() == 0) continue;
        else {
            list<int>::iterator it;
            for (it = myList[j].begin(); it != myList[j].end(); ++it)
                cout << *it << "\n";
        }
    }

    return 0;
}
