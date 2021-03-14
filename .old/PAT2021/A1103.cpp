#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, k, p, max_fac_sum = -1;
vector<int> v, ans, temp_ans;
void init(){
    int temp = 0, index = 1;
    while(temp <= n){
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}

void DFS(int index, int temp_sum, int temp_k, int fac_sum){
    if(temp_k == k){
        if(temp_sum == n && fac_sum > max_fac_sum) {
            ans = temp_ans;
            max_fac_sum = fac_sum;
        }
        return;
    }
    while(index >= 1){
        if(temp_sum + v[index] <= n){
            temp_ans[temp_k] = index;
            DFS(index, temp_sum + v[index], temp_k + 1, fac_sum + index);
        }
        if(index == 1) return;
        index--;
    }
}

int main(){
    cin >> n >> k >> p;
    init();
    temp_ans.resize(k);
    DFS(v.size()-1, 0, 0, 0);
    if(max_fac_sum == -1) {
        cout << "Impossible" << endl;
    } else{
        printf("%d = ", n);
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0) printf(" + ");
            printf("%d^%d", ans[i], p);
        }
    }
    return 0;
}