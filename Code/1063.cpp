#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<unordered_set<int>> numSets;
    for(int i = 0; i < n; i++){
        int m;
        unordered_set<int> numSet;
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            int num;
            scanf("%d", &num);
            numSet.insert(num);
        }
        numSets.push_back(numSet);
    }
    int k;
    scanf("%d", &k);
    while(k--){
        int a, b;
        scanf("%d %d", &a, &b);
        unordered_set<int> a1 = numSets[a-1];
        unordered_set<int> b1 = numSets[b-1];
        int count = a1.size();
        int nc = 0;
        for(auto num: b1){
            if(a1.find(num) == a1.end()){
                count++;
            } else{
                nc++;
            }
        }
        //cout << nc << " " << count << endl;
        printf("%.1f%%\n", float(nc*1.0/count)*100.0);
    }
    return 0;
}