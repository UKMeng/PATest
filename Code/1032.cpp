#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int n1, n2, n;
    cin >> n1 >> n2 >> n;
    unordered_map<int, int> freq;
    unordered_map<int, int> next;
    int ans = -1;
    for(int i = 0; i < n; i++){
        int t1, t2;
        char a;
        cin >> t1 >> a >> t2;
        next[t1] = t2;
    }
    while(n1 != -1){
        freq[n1] = 1;
        n1 = next[n1];
    }
    while(n2 != -1){
        if(freq[n2] == 1){
            ans = n2;
            break;
        }
        n2 = next[n2];
    }
    if(ans != -1) printf("%05d", ans);
    else printf("-1");
    return 0;
}