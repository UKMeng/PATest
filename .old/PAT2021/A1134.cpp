#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> edgea(M), edgeb(M);
    for(int i = 0; i < M; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        edgea[i] = a;
        edgeb[i] = b;
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int n;
        scanf("%d", &n);
        bool flag = true;
        unordered_map<int, bool> m;
        for(int j = 0; j < n; j++){
            int temp;
            scanf("%d", &temp);
            m[temp] = true;
        }
        for(int j = 0; j < M; j++){
            if(!m[edgea[j]] && !m[edgeb[j]]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "Yes" << endl;
        } else{
            cout << "No" << endl;
        }        
    }
    return 0;
}