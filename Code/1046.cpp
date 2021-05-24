#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> dis;
    dis.push_back(0);
    int numSum = 0;
    for(int i = 0; i < n; i++){
        int temp;
        scanf("%d",&temp);
        numSum += temp;
        dis.push_back(numSum);
    }
    int k;
    scanf("%d",&k);
    for(int i = 0; i < k; i++){
        int e1, e2;
        scanf("%d %d",&e1,&e2);
        if(e1 > e2) swap(e1, e2);
        int s1, s2;
        s1 = dis[e2-1] - dis[e1-1];
        s2 = numSum - s1;
        cout << min(s1,s2) << endl;
    }
    return 0;
}