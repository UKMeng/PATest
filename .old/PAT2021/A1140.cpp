#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(){
    string s;
    int k;
    cin >> s >> k;
    for(int i = 1; i < k; i++){
        string t;
        int count = 0;
        char now = s[0];
        for(int j = 0; j < s.size(); j++){
            if(s[j] == now){
                count++;
            } else{
                t += now + to_string(count);
                count = 1;
                now = s[j];
            }
        }
        t += now + to_string(count);
        s = t;
    }
    cout << s << endl;
    return 0;
}