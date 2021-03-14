#include <iostream>
#include <vector>
using namespace std;

int main(){
    // input
    int n, max_num;
    cin >> n >> max_num;
    vector<int> pre_sum(n+1);
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        pre_sum[i+1] = pre_sum[i] + temp;
    }

    // 滑动窗口
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n+1; j++){
            if(pre_sum[j] - pre_sum[i] <= max_num){
                count++;
            } else break;
        }
    }

    // output
    cout << count;
    return 0;
}