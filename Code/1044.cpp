#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> pre(n+1);
    unordered_map<int, int> hashMap;
    unordered_map<int, bool> isExist;
    hashMap[0] = 0;
    isExist[0] = true;
    pre[0] = 0;
    for(int i = 1; i <= n; i++){
        int temp;
        scanf("%d", &temp);
        pre[i] = pre[i-1] + temp;
        hashMap[pre[i]] = i;
        isExist[pre[i]] = true;
    }
    bool flag = true;
    while(flag){
        for(int i = 0; i <= n; i++){
            if(isExist[pre[i]+m]){
                int j = hashMap[pre[i]+m];
                cout << i+1 << "-" << j << endl;
                flag = false;
            }
        }
        if(flag) m++;
    }
    return 0;
}