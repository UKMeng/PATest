#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<char> numChar = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};
    vector<int> rgb(3);
    for(int i = 0; i < 3; i++) cin >> rgb[i];
    cout << "#";
    for(int i = 0; i < 3; i++){
        cout << numChar[rgb[i]/13] << numChar[rgb[i]%13];
    }    
    return 0;
}