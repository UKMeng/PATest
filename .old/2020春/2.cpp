#include <iostream>
#include <vector>
using namespace std;
int num[100010];
int dif[100010];
int main(){
    int n1, n2;
    cin >> n1 >> n2;
    num[n1] = 1;
    num[n2] = 1;
    dif[abs(n1-n2)] = 1;
    vector<int> list;
    list.push_back(n1);
    list.push_back(n2);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > player;
    vector<int> flag;
    for(int i = 0; i < n; i++) flag.push_back(1);
    for(int i = 0; i < n; i++) {
        vector<int> temp;
        temp.resize(m);
        for(int i = 0; i < m; i++){
            scanf("%d", &temp[i]);
        }
        player.push_back(temp);
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(flag[j] == 1){
                int a = player[j][i];
                if(num[a] == 0 && dif[a] == 1){
                    for(int i = 0; i < list.size(); i++){
                        dif[abs(list[i] - a)] = 1;
                    }
                    list.push_back(a);
                    num[a] = 1;
                } else{
                    flag[j] = 0;
                    printf("Round #%d: %d is out.\n", i + 1, j + 1);
                }
            }
        }
    }
    vector<int> ans;
    for(int i = 0; i < n; i++){
        if(flag[i] == 1) ans.push_back(i + 1);
    }
    if(ans.size() == 0) printf("No winner.\n");
    else {
        printf("Winner(s):");
        for(int i = 0; i < ans.size(); i++){
            // cout << " " << ans[i];
            printf(" %d", ans[i]);
        }
    }
    return 0;
}