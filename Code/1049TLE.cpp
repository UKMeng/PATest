#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int temp = i;
        while(temp != 0){
            if(temp % 10 == 1){
                ans++;
            }
            temp /= 10;
        }
    }
    printf("%d", ans);
    return 0;
}