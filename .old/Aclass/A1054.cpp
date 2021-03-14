#include <iostream>
#include <map>
using namespace std;
int main() {
    map<string, int> doma;
    int m, n, max = 0;
    string temp, maxNum;
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> temp;
            doma[temp]++;
        }
    }
    for(auto it = doma.begin(); it != doma.end(); it++) {
        if(it -> second > max) {
            max = it -> second;
            maxNum = it -> first;
        }
    }
    cout << maxNum;
    return 0;
}