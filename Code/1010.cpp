#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;
long long to_num(string str, int r){
    int n = str.size();
    long long ret = 0;
    for(int i = 0; i < n; i++){
        long long multi = pow(r, n-i-1);
        if(isalpha(str[i])){
            ret += ((str[i] - 'a') + 10) * multi;
        } else{
            ret += (str[i] - '0') * multi;
        }
    }
    return ret;
}
a
int main(){
    string n1, n2;
    int tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    if(tag == 2) swap(n1, n2);
    long long cmp = to_num(n1, radix);
    int maxRadix = 0;
    for(int i = 0; i < n2.size(); i++){
        if(isalpha(n2[i])){
            maxRadix = max(maxRadix, (n2[i] - 'a')+10);
        } else{
            maxRadix = max(maxRadix, n2[i] - '0');
        }
    }
    maxRadix++;
    while(true){
        long long t = to_num(n2, maxRadix);
        if(t == cmp){
            cout << maxRadix << endl;            
            break;
        } else if(t > cmp || t < maxRadix){
            cout << "Impossible" << endl;
            break;
        } else{
            maxRadix++;
        }
    }
    return 0;
}