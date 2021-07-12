#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    int start, n, k;
    cin >> start >> n >> k;
    unordered_map<int, int> node, ne;
    for(int i = 0; i < n; i++){
        int f, n, s;
        cin >> f >> n >> s;
        node[f] = n;
        ne[f] = s;
    }
    vector<int> l1;
    while(start != -1){
        l1.push_back(start);
        start = ne[start];
    }
    int pos = 0;
    while(pos + k <= l1.size()){
        reverse(l1.begin() + pos, l1.begin() + (pos + k));
        pos += k;
    }
    for(int i = 0; i < l1.size(); i++){
        if(i != l1.size()-1) printf("%05d %d %05d\n", l1[i], node[l1[i]], l1[i+1]);
        else printf("%05d %d -1\n", l1[i], node[l1[i]]);
    }
    return 0;
}