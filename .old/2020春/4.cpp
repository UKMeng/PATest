#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void find_min(vector<int> &t) {
    int min = 0x7fffffff;
    int pos = 0;
    for(int i = 0; i < t.size(); i++){
        if(t[i] < min){
            min = t[i];
            pos = i;
        }
    }
    int temp = t[0];
    t[0] = min;
    t[pos] = temp;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> num;
    vector<int> next_turn;
    num.resize(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &num[i]);
    }
    while(num.size() > 0){
        vector<int> ans;
        vector<int> temp;
        for(int i = 0; i < M; i++){
            if(num.size() > 0) {
                temp.push_back(num[0]);
                num.erase(num.begin());
            } else break;
        }
        int pos = 0;
        while(pos < num.size()){
            int pre;
            find_min(temp);
            pre = temp[0];
            ans.push_back(pre);
            temp.erase(temp.begin());
            for(pos; pos < num.size(); pos++){
                if(num[pos] >= pre) {
                    temp.push_back(num[pos]);
                    num.erase(num.begin() + pos);
                    break;
                }
            }
        }
        while(temp.size() > 0){
            find_min(temp);
            ans.push_back(temp[0]);
            temp.erase(temp.begin());
        }
        if(ans.size() != 0) {
            for(int i = 0; i < ans.size(); i++){
                if(i != 0) printf(" %d", ans[i]);
                else printf("%d", ans[i]);
            }
            cout << endl;
        }
    }
    return 0;
}