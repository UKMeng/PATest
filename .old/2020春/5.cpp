#include <iostream>     // 特别注意，排序题要是用sort超时的话就得考虑用set和map的自动排序了
#include <set>
using namespace std;
int main(){
    int n, m, index = 0, ind = 0, num[100010];
    cin >> n >> m;
    multiset<int> ans[1000], m1, m2;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        if(i < m){
            m1.insert(num[i]);
            ans[0].insert(num[i]);
        }
    }
    for(int i = m; i < n; i++){
        if(num[i] > *m1.begin()){
            ans[index].insert(num[i]);
            m1.erase(m1.begin());
            m1.insert(num[i]);
        } else{
            m2.insert(num[i]);
            m1.erase(m1.begin());
            ans[index+1].insert(num[i]);
        }
        if(m1.size() == 0){
            index++;
            m1 = m2;
            m2.clear();
        }
    }
    while(ans[ind].size() != 0) ind++;
    for(int i = 0; i < ind; i++){
        int st = 0;
        for(int nn:ans[i]){
            if(st!=0) cout << " ";
            cout << nn;
            st++;
        }
        cout << endl;
    }
    return 0;
}