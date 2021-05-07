#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    vector<int> s1, s2;
    scanf("%d", &n);
    s1.resize(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &s1[i]);
    }
    scanf("%d", &m);
    s2.resize(m);
    for(int i = 0; i < m; i++){
        scanf("%d", &s2[i]);
    }
    int end = (m + n - 1) / 2;
    int l1 = 0, l2 = 0;
    int ans;
    for(int i = 0; i <= end; i++){
        if(l1 < n && l2 < m){
            if(s1[l1] < s2[l2]){
                ans = s1[l1];
                l1++;
            } else{
                ans = s2[l2];
                l2++;
            }
        } else if(l1 == n){
            ans = s2[l2];
            l2++;
        } else if(l2 == m){
            ans = s1[l1];
            l1++;
        }
    }
    cout << ans << endl;
    return 0;
}