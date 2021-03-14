#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string a, sq;
    int n, m;
    cin >> a;
    cin >> sq;
    n = a.size();
    m = sq.size();
    int sq_l = 0;
    int l = 0, min_l = 999999, ans_l;
    for(int i = 0; i < n; i++){
        if(sq[sq_l] == a[i]){
            if(sq_l == 0){
                l = i;
                sq_l++;
            } else if(sq_l == m-1){
                if(i - l + 1 < min_l){
                    min_l = i - l + 1;
                    ans_l = l;
                }
                i = l; // i会再自动+1
                sq_l = 0;
            } else{
                sq_l++;
            }
        }
    }
    cout << a.substr(ans_l, min_l);
    return 0;
}