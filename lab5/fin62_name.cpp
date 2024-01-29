#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int count_s = s.length();
    int count_t = t.length();

    int count = 0;
    int j = 0;

    for (int i = 0; i < count_t; i++) {
        if (t[i] == s[j]) {
            j++;
            if (j == count_s) {
                count++;
                j = 0;
            }
        }
    }

    cout << count << endl;

    return 0;
}
