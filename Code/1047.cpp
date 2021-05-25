#include <iostream>
#include <vector>
#include <algorithm>   // 用cin会超时
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<string>> sinc(m+1);
    for(int i = 0; i < n; i++){
        string name;
        char s[5];
        int k;
        scanf("%s %d", s, &k);
        name = s;
        for(int j = 0; j < k; j++){
            int temp;
            scanf("%d", &temp);
            sinc[temp].push_back(name);
        }
    }
    for(int i = 1; i < m+1; i++){
        //cout << i << " " << sinc[i].size() << endl;
        printf("%d %d\n", i, sinc[i].size());
        sort(sinc[i].begin(), sinc[i].end());
        for(int j = 0; j < sinc[i].size(); j++){
            printf("%s\n", sinc[i][j].c_str());
        }
    }
    return 0;
}