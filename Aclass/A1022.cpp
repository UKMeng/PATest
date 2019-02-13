#include <iostream>
#include <map>
#include <set>
#include <cstring>
using namespace std;
map<string, set<string> > dgb[5];
int main() {
    int n, qn;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string id;
        cin >> id;
        getchar();
        for(int j = 0; j < 5; j++) {
            string temp;
            getline(cin, temp);
            if(j == 2) {
                string a;
                for(int k = 0; k < temp.size(); k++) {
                    if(temp[k] != ' ') a += temp[k];
                    if(temp[k] == ' ' || k == temp.size() - 1) {
                        dgb[j][a].insert(id);
                        a.clear();
                    }
                }
            }
            else dgb[j][temp].insert(id);
        }
    }
    cin >> qn;
    getchar();
    for(int i = 0; i < qn; i++) {
        string temp;
        getline(cin, temp);
        cout << temp << endl;
        int t = (temp[0] - '0') - 1;
        temp.erase(temp.begin(), temp.begin() + 3);
        if(dgb[t].find(temp) == dgb[t].end()) cout << "Not Found" << endl;
        else for(auto it = dgb[t][temp].begin(); it != dgb[t][temp].end(); it++) cout << *it << endl; 
    }
    return 0;
}