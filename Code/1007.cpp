#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> num(n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);

    // 双重循环
    int ans = -0x3f3f3f3f;
    int front = 0, rear = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum += num[j];
            if(sum > ans){
                ans = sum;
                front = i;
                rear = j;
            }
        }
    }

    // 动态规划
    int dp = num[0];
    int ans = num[0];
    int prel = 0, front = 0, rear = 0;
    for(int i = 1; i < n; i++){
        if(dp + num[i] < num[i]){
            dp = num[i];
            prel = i;
        } else dp = dp + num[i];
        if(dp > ans) {
            ans = dp;
            front = prel;
            rear = i;
        }
    }
    

    // 贪心
    int ans = -0x3f3f3f3f;
    int sum = 0;
    int pre = 0, front, rear;
    for(int i = 0; i < n; i++){
        sum += num[i];
        if(sum > ans){
            ans = sum;
            front = pre;
            rear = i;
        }
        if(sum < 0){
            sum = 0;
            pre = i + 1;
        }
    }


    if(ans < 0) cout << 0 << " " << num[0] << " " << num[n-1] << endl;
    else cout << ans << " " << num[front] << " " << num[rear] << endl;
    return 0;
}