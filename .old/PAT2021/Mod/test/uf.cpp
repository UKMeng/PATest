#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> r, f; // r = rank, f = father
int n;

int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}

bool union_set(int x, int y){
    int fx = find(x), fy = find(y);
    if(fx == fy) return false;
    else{
        if(r[fx] < r[fy]) swap(fx, fy);
        r[fx] += r[fy];
        f[fy] = fx;
        return true;
    }
}

int main(){
    cin >> n;
    r.resize(n, 1);
    f.resize(n);
    for(int i = 0; i < n; i++){
        f[i] = i;
    }
    return 0;
}