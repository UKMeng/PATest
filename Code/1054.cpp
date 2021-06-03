#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    int n, m;
    scanf("%d %d",&n,&m);
    unordered_map<int, int> mp;
    int maxCount = -1, ans = -1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int tmp;
            scanf("%d", &tmp);
            mp[tmp]++;
            if(mp[tmp] > maxCount) {
                maxCount = mp[tmp];
                ans = tmp;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}