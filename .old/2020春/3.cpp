#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(){
    int n, r, k;
    vector<int> G[510];
    cin >> n >> r >> k;
    for(int i = 0; i < r; i++){
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    int query;
    cin >> query;
    for(int i = 0; i < query; i++){
        set<int> spi;
        vector<int> plan;
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            spi.insert(a);
            plan.push_back(a);
        }
        if(spi.size() < k){
            cout << "Error: Too few species." << endl;
        } else if(spi.size() > k) {
            cout << "Error: Too many species." << endl;
        } else{
            int flag = 1;
            for(int j = 0; j < n; j++){
                for(int p = 0; p < G[j].size(); p++){
                    if(plan[G[j][p]] == plan[j]){
                        flag = 0;
                        break;
                    }
                }
                if(flag == 0) break;
            }
            if(flag == 0) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
    return 0;
}