#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> num;
    num.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &num[i]);
    vector<int> left_max, right_min;
    vector<int> ans;
    left_max.resize(n);
    right_min.resize(n);
    int MAX = num[0], MIN = num[n-1];
    for(int i = 0; i < n; i++){
        if(num[i] > MAX) MAX = num[i];
        left_max[i] = MAX;
        if(num[n-1-i] < MIN) MIN = num[n-1-i];
        right_min[n-1-i] = MIN;
    }
    for(int i = 0; i < n; i++){
        if(num[i] >= left_max[i] && num[i] <= right_min[i]){
            ans.push_back(num[i]);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) printf(" %d", ans[i]);
        else printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}