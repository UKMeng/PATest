#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, p;
    scanf("%d %d", &n, &p);
    vector<int> land(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &land[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int sum = land[i];
        if(sum <= p) ans++;
        else continue;
        for(int j = i + 1; j < n; j++){
            sum += land[j];
            if(sum <= p) ans++;
            else break;
        }
    }
    printf("%d", ans);
    return 0;
}